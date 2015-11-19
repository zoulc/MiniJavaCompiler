define i32 @main() {
entry:
  %a = alloca i64
  store i64 1, i64* %a
  %loadvar = load i64, i64* %a
  %ultcmptmp = icmp ult i64 %loadvar, 5
  %whilefirstcondexpr = icmp ne i1 %ultcmptmp, false
  br i1 %whilefirstcondexpr, label %whilebody, label %afterloop

whilebody:                                        ; preds = %whilebody, %entry
  %loadvar1 = load i64, i64* %a
  %addtmp = add i64 %loadvar1, 1
  store i64 %addtmp, i64* %a
  %loadvar2 = load i64, i64* %a
  %ultcmptmp3 = icmp ult i64 %loadvar2, 5
  %whileloopcondexpr = icmp ne i1 %ultcmptmp3, false
  br i1 %whileloopcondexpr, label %whilebody, label %afterloop
                                                  ; No predecessors!

afterloop:                                        ; preds = %whilebody, %entry
  ret i32 0
}
