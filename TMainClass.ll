define i64 @main() {
entry:
  %a = alloca i64
  store i64 1, i64* %a
  %loadvar = load i64, i64* %a
  %ultcmptmp = icmp ult i64 %loadvar, 3
  %ifcond = icmp ne i1 %ultcmptmp, false
  br i1 %ifcond, label %then, label %else

then:                                             ; preds = %entry
  %loadvar1 = load i64, i64* %a
  %addtmp = add i64 %loadvar1, 1
  store i64 %addtmp, i64* %a
  br label %ifcont

else:                                             ; preds = %entry
  %loadvar2 = load i64, i64* %a
  %loadvar3 = load i64, i64* %a
  %addtmp4 = add i64 %loadvar2, %loadvar3
  store i64 %addtmp4, i64* %a
  br label %ifcont

ifcont:                                           ; preds = %else, %then
  %0 = load i64, i64* %a
  ret i64 1
}
