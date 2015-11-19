%Tester_vtable = type { i64 (%Tester*)* }
%Tester = type { %Tester_vtable*, i64 }
%Tseter2 = type { %Tseter2_vtable*, i64, i64 }
%Tseter2_vtable = type { i64 (%Tseter2*)* }

@Tester_vatble_loc = constant %Tester_vtable { i64 (%Tester*)* @Tester_work }

define i64 @Tester_work(%Tester*) {
work_entry:
  %1 = load %Tester, %Tester* %0
  %2 = alloca %Tester
  %3 = getelementptr inbounds %Tester, %Tester* %0, i32 0, i32 1
  %loadvar = load i64, i64* %3
  %addtmp = add i64 %loadvar, 1
  ret i64 %addtmp
}

define i64 @Tseter2_work(%Tseter2*) {
work_entry:
  %1 = load %Tseter2, %Tseter2* %0
  %2 = alloca %Tseter2
  %3 = getelementptr inbounds %Tseter2, %Tseter2* %0, i32 0, i32 1
  %4 = getelementptr inbounds %Tseter2, %Tseter2* %0, i32 0, i32 2
  %loadvar = load i64, i64* %4
  %addtmp = add i64 %loadvar, 1
  ret i64 %addtmp
}

define i32 @main() {
entry:
  %a = alloca i64
  store i64 1, i64* %a
  %loadvar = load i64, i64* %a
  %ultcmptmp = icmp ult i64 %loadvar, 10
  %whilefirstcondexpr = icmp ne i1 %ultcmptmp, false
  br i1 %whilefirstcondexpr, label %whilebody, label %afterloop

whilebody:                                        ; preds = %whilebody, %entry
  %loadvar1 = load i64, i64* %a
  %addtmp = add i64 %loadvar1, 1
  store i64 %addtmp, i64* %a
  %loadvar2 = load i64, i64* %a
  %ultcmptmp3 = icmp ult i64 %loadvar2, 10
  %whileloopcondexpr = icmp ne i1 %ultcmptmp3, false
  br i1 %whileloopcondexpr, label %whilebody, label %afterloop

afterloop:                                        ; preds = %whilebody, %entry
  %b = alloca %Tester*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%Tester* getelementptr (%Tester, %Tester* null, i32 1) to i64))
  %0 = bitcast i8* %malloccall to %Tester*
  %1 = getelementptr inbounds %Tester, %Tester* %0, i32 0, i32 0
  store %Tester_vtable* @Tester_vatble_loc, %Tester_vtable** %1
  store %Tester* %0, %Tester** %b
  %loadvar4 = load %Tester*, %Tester** %b
  %2 = getelementptr inbounds %Tester, %Tester* %loadvar4, i32 0, i32 0
  %3 = load %Tester_vtable*, %Tester_vtable** %2
  %4 = getelementptr inbounds %Tester_vtable, %Tester_vtable* %3, i32 0, i32 0
  %5 = load i64 (%Tester*)*, i64 (%Tester*)** %4
  %6 = call i64 %5(%Tester* %loadvar4)
  store i64 %6, i64* %a
  ret i32 0
}
declare noalias i8* @malloc(i64)

