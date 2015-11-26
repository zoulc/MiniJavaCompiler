; ModuleID = 'my cool mini-java'

@0 = private unnamed_addr constant [6 x i8] c"%lld\0A\00"

define i32 @main() {
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
  %loadvar5 = load i64, i64* %a
  %0 = call i32 @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @0, i32 0, i32 0), i64 %loadvar5)
  ret i32 0
}

declare i32 @printf(i8*, i64)

