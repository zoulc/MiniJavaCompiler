; ModuleID = 'my cool mini-java'

%Tester2_vtable = type { i64 (%Tester*)*, i64 (%Tester*)* }
%Tester = type { i64, %Tester_vtable*, i64 }
%Tester_vtable = type { i64 (%Tester*)*, i64 (%Tester*)* }
%Reader_vtable = type { i64 (%Reader*, i64*)* }
%Reader = type { i64, %Reader_vtable*, i64 }
%Tester2 = type { i64, %Tester2_vtable*, i64 }

@Tester2_vatble_loc = constant %Tester2_vtable { i64 (%Tester*)* @Tester_set, i64 (%Tester*)* @Tester2_work }
@0 = private unnamed_addr constant [6 x i8] c"%lld\0A\00"
@Reader_vatble_loc = constant %Reader_vtable { i64 (%Reader*, i64*)* @Reader_read }
@1 = private unnamed_addr constant [6 x i8] c"%lld\0A\00"
@2 = private unnamed_addr constant [6 x i8] c"%lld\0A\00"

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
  %loadvar = load i64, i64* %5
  %addtmp = add i64 %loadvar, 2
  store i64 %addtmp, i64* %5
  %loadvar1 = load i64, i64* %5
  ret i64 %loadvar1
}

define i64 @Container_set(i64*) {
  %2 = load i64, i64* %0
  %3 = icmp eq i64 %2, 1
  br i1 %3, label %4, label %12

; <label>:4                                       ; preds = %1
  %5 = bitcast i64* %0 to %Tester*
  %6 = bitcast i64* %0 to %Tester*
  %7 = getelementptr inbounds %Tester, %Tester* %5, i32 0, i32 1
  %8 = load %Tester_vtable*, %Tester_vtable** %7
  %9 = getelementptr inbounds %Tester_vtable, %Tester_vtable* %8, i32 0, i32 0
  %10 = load i64 (%Tester*)*, i64 (%Tester*)** %9
  %11 = call i64 %10(%Tester* %6)
  ret i64 %11

; <label>:12                                      ; preds = %1
  %13 = icmp eq i64 %2, 2
  br i1 %13, label %14, label %22

; <label>:14                                      ; preds = %12
  %15 = bitcast i64* %0 to %Tester2*
  %16 = bitcast i64* %0 to %Tester*
  %17 = getelementptr inbounds %Tester2, %Tester2* %15, i32 0, i32 1
  %18 = load %Tester2_vtable*, %Tester2_vtable** %17
  %19 = getelementptr inbounds %Tester2_vtable, %Tester2_vtable* %18, i32 0, i32 0
  %20 = load i64 (%Tester*)*, i64 (%Tester*)** %19
  %21 = call i64 %20(%Tester* %16)
  ret i64 %21

; <label>:22                                      ; preds = %12
  ret i64 0
}

define i64 @Container_work(i64*) {
  %2 = load i64, i64* %0
  %3 = icmp eq i64 %2, 1
  br i1 %3, label %4, label %12

; <label>:4                                       ; preds = %1
  %5 = bitcast i64* %0 to %Tester*
  %6 = bitcast i64* %0 to %Tester*
  %7 = getelementptr inbounds %Tester, %Tester* %5, i32 0, i32 1
  %8 = load %Tester_vtable*, %Tester_vtable** %7
  %9 = getelementptr inbounds %Tester_vtable, %Tester_vtable* %8, i32 0, i32 1
  %10 = load i64 (%Tester*)*, i64 (%Tester*)** %9
  %11 = call i64 %10(%Tester* %6)
  ret i64 %11

; <label>:12                                      ; preds = %1
  %13 = icmp eq i64 %2, 2
  br i1 %13, label %14, label %22

; <label>:14                                      ; preds = %12
  %15 = bitcast i64* %0 to %Tester2*
  %16 = bitcast i64* %0 to %Tester*
  %17 = getelementptr inbounds %Tester2, %Tester2* %15, i32 0, i32 1
  %18 = load %Tester2_vtable*, %Tester2_vtable** %17
  %19 = getelementptr inbounds %Tester2_vtable, %Tester2_vtable* %18, i32 0, i32 1
  %20 = load i64 (%Tester*)*, i64 (%Tester*)** %19
  %21 = call i64 %20(%Tester* %16)
  ret i64 %21

; <label>:22                                      ; preds = %12
  ret i64 0
}

define i64 @Reader_read(%Reader*, i64*) {
read_entry:
  %2 = alloca %Reader*
  store %Reader* %0, %Reader** %2
  %3 = alloca i64*
  store i64* %1, i64** %3
  %4 = load %Reader, %Reader* %0
  %5 = alloca %Reader
  %6 = getelementptr inbounds %Reader, %Reader* %0, i32 0, i32 2
  %loadvar = load i64*, i64** %3
  %7 = call i64 @Container_work(i64* %loadvar)
  store i64 %7, i64* %6
  %loadvar1 = load i64, i64* %6
  ret i64 %loadvar1
}

define i32 @main() {
entry:
  %a = alloca i64
  %b = alloca %Tester*
  %c = alloca %Reader*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%Tester2* getelementptr (%Tester2, %Tester2* null, i32 1) to i64))
  %0 = bitcast i8* %malloccall to %Tester2*
  %1 = getelementptr inbounds %Tester2, %Tester2* %0, i32 0, i32 1
  store %Tester2_vtable* @Tester2_vatble_loc, %Tester2_vtable** %1
  %2 = getelementptr inbounds %Tester2, %Tester2* %0, i32 0, i32 0
  store i64 2, i64* %2
  %3 = bitcast %Tester** %b to %Tester2**
  store %Tester2* %0, %Tester2** %3
  %loadvar = load %Tester*, %Tester** %b
  %4 = getelementptr inbounds %Tester, %Tester* %loadvar, i32 0, i32 1
  %5 = load %Tester_vtable*, %Tester_vtable** %4
  %6 = getelementptr inbounds %Tester_vtable, %Tester_vtable* %5, i32 0, i32 0
  %7 = load i64 (%Tester*)*, i64 (%Tester*)** %6
  %8 = call i64 %7(%Tester* %loadvar)
  store i64 %8, i64* %a
  %loadvar1 = load i64, i64* %a
  %9 = call i64 @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @0, i32 0, i32 0), i64 %loadvar1)
  %malloccall.2 = tail call i8* @malloc(i64 ptrtoint (%Reader* getelementptr (%Reader, %Reader* null, i32 1) to i64))
  %10 = bitcast i8* %malloccall.2 to %Reader*
  %11 = getelementptr inbounds %Reader, %Reader* %10, i32 0, i32 1
  store %Reader_vtable* @Reader_vatble_loc, %Reader_vtable** %11
  %12 = getelementptr inbounds %Reader, %Reader* %10, i32 0, i32 0
  store i64 3, i64* %12
  store %Reader* %10, %Reader** %c
  %loadvar3 = load %Reader*, %Reader** %c
  %loadvar4 = load %Tester*, %Tester** %b
  %13 = bitcast %Tester* %loadvar4 to i64*
  %14 = getelementptr inbounds %Reader, %Reader* %loadvar3, i32 0, i32 1
  %15 = load %Reader_vtable*, %Reader_vtable** %14
  %16 = getelementptr inbounds %Reader_vtable, %Reader_vtable* %15, i32 0, i32 0
  %17 = load i64 (%Reader*, i64*)*, i64 (%Reader*, i64*)** %16
  %18 = call i64 %17(%Reader* %loadvar3, i64* %13)
  store i64 %18, i64* %a
  %loadvar5 = load i64, i64* %a
  %19 = call i64 @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @1, i32 0, i32 0), i64 %loadvar5)
  %loadvar6 = load %Tester*, %Tester** %b
  %20 = getelementptr inbounds %Tester, %Tester* %loadvar6, i32 0, i32 1
  %21 = load %Tester_vtable*, %Tester_vtable** %20
  %22 = getelementptr inbounds %Tester_vtable, %Tester_vtable* %21, i32 0, i32 1
  %23 = load i64 (%Tester*)*, i64 (%Tester*)** %22
  %24 = call i64 %23(%Tester* %loadvar6)
  store i64 %24, i64* %a
  %loadvar7 = load i64, i64* %a
  %25 = call i64 @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @2, i32 0, i32 0), i64 %loadvar7)
  ret i32 0
}

declare noalias i8* @malloc(i64)

declare i64 @printf(i8*, i64)
