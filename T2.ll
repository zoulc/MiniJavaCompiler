%Tester_vtable = type { i64 (%Tester*)*, i64 (%Tester*)* }
%Tester = type { %Tester_vtable*, i64 }
%Tseter2 = type { %Tseter2_vtable*, i64, i64 }
%Tseter2_vtable = type { i64 (%Tester*)*, i64 (%Tseter2*)* }

@Tester_vatble_loc = constant %Tester_vtable { i64 (%Tester*)* @Tester_set, i64 (%Tester*)* @Tester_work }
@0 = private unnamed_addr constant [6 x i8] c"%lld\0A\00"
@1 = private unnamed_addr constant [6 x i8] c"%lld\0A\00"

define i64 @Tester_set(%Tester*) {
set_entry:
  %1 = getelementptr inbounds %Tester, %Tester* %0, i64 0, i32 1
  store i64 0, i64* %1, align 4
  ret i64 0
}

define i64 @Tester_work(%Tester*) {
work_entry:
  %1 = getelementptr inbounds %Tester, %Tester* %0, i64 0, i32 1
  %loadvar = load i64, i64* %1, align 4
  %addtmp = add i64 %loadvar, 1
  store i64 %addtmp, i64* %1, align 4
  ret i64 %addtmp
}

define i64 @Tseter2_work(%Tseter2*) {
work_entry:
  %1 = getelementptr inbounds %Tseter2, %Tseter2* %0, i64 0, i32 2
  %loadvar = load i64, i64* %1, align 4
  %addtmp = add i64 %loadvar, 2
  store i64 %addtmp, i64* %1, align 4
  ret i64 %addtmp
}

define i32 @main() {
entry:
  %a = alloca i64
  %b = alloca %Tester*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%Tester* getelementptr (%Tester, %Tester* null, i32 1) to i64))
  %0 = bitcast i8* %malloccall to %Tester*
  %1 = getelementptr inbounds %Tester, %Tester* %0, i32 0, i32 0
  store %Tester_vtable* @Tester_vatble_loc, %Tester_vtable** %1
  store %Tester* %0, %Tester** %b
  %loadvar = load %Tester*, %Tester** %b
  %2 = getelementptr inbounds %Tester, %Tester* %loadvar, i32 0, i32 0
  %3 = load %Tester_vtable*, %Tester_vtable** %2
  %4 = getelementptr inbounds %Tester_vtable, %Tester_vtable* %3, i32 0, i32 0
  %5 = load i64 (%Tester*)*, i64 (%Tester*)** %4
  %6 = call i64 %5(%Tester* %loadvar)
  store i64 %6, i64* %a
  %loadvar1 = load %Tester*, %Tester** %b
  %7 = getelementptr inbounds %Tester, %Tester* %loadvar1, i32 0, i32 0
  %8 = load %Tester_vtable*, %Tester_vtable** %7
  %9 = getelementptr inbounds %Tester_vtable, %Tester_vtable* %8, i32 0, i32 1
  %10 = load i64 (%Tester*)*, i64 (%Tester*)** %9
  %11 = call i64 %10(%Tester* %loadvar1)
  store i64 %11, i64* %a
  %loadvar2 = load i64, i64* %a
  %12 = call i64 @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @0, i32 0, i32 0), i64 %loadvar2)
  %loadvar3 = load %Tester*, %Tester** %b
  %13 = getelementptr inbounds %Tester, %Tester* %loadvar3, i32 0, i32 0
  %14 = load %Tester_vtable*, %Tester_vtable** %13
  %15 = getelementptr inbounds %Tester_vtable, %Tester_vtable* %14, i32 0, i32 1
  %16 = load i64 (%Tester*)*, i64 (%Tester*)** %15
  %17 = call i64 %16(%Tester* %loadvar3)
  store i64 %17, i64* %a
  %loadvar4 = load i64, i64* %a
  %18 = call i64 @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @1, i32 0, i32 0), i64 %loadvar4)
  ret i32 0
}

declare noalias i8* @malloc(i64)

declare i64 @printf(i8*, i64)
