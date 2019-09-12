module Config = struct
  let verbose = ref false
end

let cmd_opts =
  let open Arg in
  align [
    "-v", Set Config.verbose,
    "	Verbose output" ;
  ]

let process_file f =
  assert (Filename.check_suffix f ".bx") ;
  Format.printf "Processing %S...@." f ;
  let ch = open_in f in
  let lb = Lexing.from_channel ch in
  lb.lex_curr_p <- {lb.lex_curr_p with pos_fname = f} ;
  try begin
    let prog = Parser.prog Lexer.token lb in
    (* Format.printf "done; program follows:@." ;
     * Format.printf "%a@." Ast.Source.pp_prog prog ; *)
    let cf = (Filename.chop_suffix f ".bx") ^ ".c" in
    let cch = open_out cf in
    let cchf = Format.formatter_of_out_channel cch in
    Format.fprintf cchf "/* %s */@." f ;
    let cres = Compile.compile prog in
    Codegen.codegen cchf cres ;
    Format.pp_print_flush cchf () ;
    close_out cch ;
    Format.printf "Wrote %S.@." cf ;
    let cmd = Printf.sprintf "gcc -o %s %s"
        (Filename.chop_suffix f ".bx") cf in
    Format.printf "Running: %s@." cmd ;
    assert (Sys.command cmd == 0)
  end with
  | Parser.Error ->
      let open Lexing in
      Format.eprintf "Parse error at %S:%d.%d\n"
        lb.lex_curr_p.pos_fname
        lb.lex_curr_p.pos_lnum
        (lb.lex_curr_p.pos_cnum - lb.lex_curr_p.pos_bol)

let main () =
  let files = ref [] in
  Arg.parse cmd_opts
    (fun f -> files := f :: !files)
    (Printf.sprintf "Usage: %s [OPTIONS] file1 ..."
       (Filename.basename Sys.executable_name)) ;
  List.iter process_file (List.rev !files)

let () =
  if not !Sys.interactive then
    main ()
