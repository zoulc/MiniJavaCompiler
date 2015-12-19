; ModuleID = 'my cool mini-java'

@0 = private unnamed_addr constant [5 x i8] c"%lld\00"
@1 = private unnamed_addr constant [6 x i8] c"%lld\0A\00"

define i32 @main() {
entry:
  %a = alloca i64
  %0 = alloca i64
  %1 = call i64 @scanf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @0, i32 0, i32 0), i64* %0)
  %2 = load i64, i64* %0
  store i64 %2, i64* %a
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

afterloop:                                        ; preds = %whilebody, %entry
  %loadvar4 = load i64, i64* %a
  %3 = call i64 @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @1, i32 0, i32 0), i64 %loadvar4)
  ret i32 0
}

declare i64 @scanf(i8*, i64*)

declare i64 @printf(i8*, i64)

