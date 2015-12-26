; ModuleID = 'my cool mini-java'

%Tester_vtable = type { i64 (%Tester*)*, i64 (%Tester*)* }
%Tester = type { i64, %Tester_vtable*, i64 }
%Tester2_vtable = type { i64 (%Tester*)*, i64 (%Tester*)*, i64 (%Tester2*, %Tester*)* }
%Tester2 = type { i64, %Tester2_vtable*, i64, i64 }

@Tester_vatble_loc = constant %Tester_vtable { i64 (%Tester*)* @Tester_set, i64 (%Tester*)* @Tester_work }
@0 = private unnamed_addr constant [6 x i8] c"%lld\0A\00"
@Tester2_vatble_loc = constant %Tester2_vtable { i64 (%Tester*)* @Tester_set, i64 (%Tester*)* @Tester2_work, i64 (%Tester2*, %Tester*)* @Tester2_seek }
@1 = private unnamed_addr constant [6 x i8] c"%lld\0A\00"

define i64 @Tester_set(%Tester*) {
set_entry:
  %1 = alloca %Tester*
  store %Tester* %0, %Tester** %1
  %2 = load %Tester, %Tester* %0
  %3 = alloca %Tester
  %4 = getelementptr inbounds %Tester, %Tester* %0, i32 0, i32 2
  store i64 0, i64* %4
  ret i64 0
}

define i64 @Tester_work(%Tester*) {
work_entry:
  %1 = alloca %Tester*
  store %Tester* %0, %Tester** %1
  %2 = load %Tester, %Tester* %0
  %3 = alloca %Tester
  %4 = getelementptr inbounds %Tester, %Tester* %0, i32 0, i32 2
  %loadvar = load i64, i64* %4
  %addtmp = add i64 %loadvar, 1
  store i64 %addtmp, i64* %4
  %loadvar1 = load i64, i64* %4
  ret i64 %loadvar1
}

define i64 @Tester2_work(%Tester*) {
work_entry:
  %1 = bitcast %Tester* %0 to %Tester2*
  %2 = alloca %Tester2*
  store %Tester2* %1, %Tester2** %2
  %3 = load %Tester2, %Tester2* %1
  %4 = alloca %Tester2
  %5 = getelementptr inbounds %Tester2, %Tester2* %1, i32 0, i32 2
  %6 = getelementptr inbounds %Tester2, %Tester2* %1, i32 0, i32 3
  %loadvar = load i64, i64* %6
  %addtmp = add i64 %loadvar, 2
  store i64 %addtmp, i64* %6
  %loadvar1 = load i64, i64* %6
  ret i64 %loadvar1
}

define i64 @Tester2_seek(%Tester2*, %Tester*) {
seek_entry:
  %2 = alloca %Tester2*
  store %Tester2* %0, %Tester2** %2
  %3 = alloca %Tester*
  store %Tester* %1, %Tester** %3
  %4 = load %Tester2, %Tester2* %0
  %5 = alloca %Tester2
  %6 = getelementptr inbounds %Tester2, %Tester2* %0, i32 0, i32 2
  %7 = getelementptr inbounds %Tester2, %Tester2* %0, i32 0, i32 3
  %loadvar = load %Tester*, %Tester** %3
  %8 = getelementptr inbounds %Tester, %Tester* %loadvar, i32 0, i32 1
  %9 = load %Tester_vtable*, %Tester_vtable** %8
  %10 = getelementptr inbounds %Tester_vtable, %Tester_vtable* %9, i32 0, i32 1
  %11 = load i64 (%Tester*)*, i64 (%Tester*)** %10
  %12 = call i64 %11(%Tester* %loadvar)
  ret i64 %12
}

define i32 @main() {
entry:
  %a = alloca i64
  %b = alloca %Tester*
  %c = alloca %Tester2*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%Tester* getelementptr (%Tester, %Tester* null, i32 1) to i64))
  %0 = bitcast i8* %malloccall to %Tester*
  %1 = getelementptr inbounds %Tester, %Tester* %0, i32 0, i32 1
  store %Tester_vtable* @Tester_vatble_loc, %Tester_vtable** %1
  %2 = getelementptr inbounds %Tester, %Tester* %0, i32 0, i32 0
  store i64 1, i64* %2
  store %Tester* %0, %Tester** %b
  %loadvar = load %Tester*, %Tester** %b
  %3 = getelementptr inbounds %Tester, %Tester* %loadvar, i32 0, i32 1
  %4 = load %Tester_vtable*, %Tester_vtable** %3
  %5 = getelementptr inbounds %Tester_vtable, %Tester_vtable* %4, i32 0, i32 0
  %6 = load i64 (%Tester*)*, i64 (%Tester*)** %5
  %7 = call i64 %6(%Tester* %loadvar)
  store i64 %7, i64* %a
  %loadvar1 = load %Tester*, %Tester** %b
  %8 = getelementptr inbounds %Tester, %Tester* %loadvar1, i32 0, i32 1
  %9 = load %Tester_vtable*, %Tester_vtable** %8
  %10 = getelementptr inbounds %Tester_vtable, %Tester_vtable* %9, i32 0, i32 1
  %11 = load i64 (%Tester*)*, i64 (%Tester*)** %10
  %12 = call i64 %11(%Tester* %loadvar1)
  store i64 %12, i64* %a
  %loadvar2 = load i64, i64* %a
  %13 = call i64 @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @0, i32 0, i32 0), i64 %loadvar2)
  %malloccall.3 = tail call i8* @malloc(i64 ptrtoint (%Tester2* getelementptr (%Tester2, %Tester2* null, i32 1) to i64))
  %14 = bitcast i8* %malloccall.3 to %Tester2*
  %15 = getelementptr inbounds %Tester2, %Tester2* %14, i32 0, i32 1
  store %Tester2_vtable* @Tester2_vatble_loc, %Tester2_vtable** %15
  %16 = getelementptr inbounds %Tester2, %Tester2* %14, i32 0, i32 0
  store i64 2, i64* %16
  store %Tester2* %14, %Tester2** %c
  %loadvar4 = load %Tester2*, %Tester2** %c
  %loadvar5 = load %Tester*, %Tester** %b
  %17 = getelementptr inbounds %Tester2, %Tester2* %loadvar4, i32 0, i32 1
  %18 = load %Tester2_vtable*, %Tester2_vtable** %17
  %19 = getelementptr inbounds %Tester2_vtable, %Tester2_vtable* %18, i32 0, i32 2
  %20 = load i64 (%Tester2*, %Tester*)*, i64 (%Tester2*, %Tester*)** %19
  %21 = call i64 %20(%Tester2* %loadvar4, %Tester* %loadvar5)
  store i64 %21, i64* %a
  %loadvar6 = load i64, i64* %a
  %22 = call i64 @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @1, i32 0, i32 0), i64 %loadvar6)
  ret i32 0
}

declare noalias i8* @malloc(i64)

declare i64 @printf(i8*, i64)
