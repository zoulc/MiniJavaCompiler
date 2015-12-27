; ModuleID = 'my cool mini-java'

%"Templt#int_vtable" = type { i64 (%Base*)*, i64 (%"Templt#int"*)*, i64 (%"Templt#int"*, i64)* }
%Base = type { i64, %Base_vtable*, i64 }
%Base_vtable = type { i64 (%Base*)* }
%"Templt#int" = type { i64, %"Templt#int_vtable"*, i64, i64 }

@"Templt#int_vatble_loc" = constant %"Templt#int_vtable" { i64 (%Base*)* @Base_init, i64 (%"Templt#int"*)* @"Templt#int_getVal", i64 (%"Templt#int"*, i64)* @"Templt#int_setVal" }
@Base_vatble_loc = constant %Base_vtable { i64 (%Base*)* @Base_init }
@0 = private unnamed_addr constant [6 x i8] c"%lld\0A\00"

define i64 @Base_init(%Base*) {
init_entry:
  %1 = alloca %Base*
  store %Base* %0, %Base** %1
  %2 = load %Base, %Base* %0
  %3 = alloca %Base
  %4 = getelementptr inbounds %Base, %Base* %0, i32 0, i32 2
  store i64 0, i64* %4
  ret i64 0
}

define i64 @"Templt#int_getVal"(%"Templt#int"*) {
getVal_entry:
  %1 = alloca %"Templt#int"*
  store %"Templt#int"* %0, %"Templt#int"** %1
  %2 = load %"Templt#int", %"Templt#int"* %0
  %3 = alloca %"Templt#int"
  %4 = getelementptr inbounds %"Templt#int", %"Templt#int"* %0, i32 0, i32 2
  %5 = getelementptr inbounds %"Templt#int", %"Templt#int"* %0, i32 0, i32 3
  %loadvar = load i64, i64* %5
  ret i64 %loadvar
}

define i64 @"Templt#int_setVal"(%"Templt#int"*, i64) {
setVal_entry:
  %2 = alloca %"Templt#int"*
  store %"Templt#int"* %0, %"Templt#int"** %2
  %3 = alloca i64
  store i64 %1, i64* %3
  %4 = load %"Templt#int", %"Templt#int"* %0
  %5 = alloca %"Templt#int"
  %6 = getelementptr inbounds %"Templt#int", %"Templt#int"* %0, i32 0, i32 2
  %7 = getelementptr inbounds %"Templt#int", %"Templt#int"* %0, i32 0, i32 3
  %loadvar = load i64, i64* %3
  store i64 %loadvar, i64* %7
  ret i64 0
}

define i32 @main() {
entry:
  %t = alloca %"Templt#int"*
  %b = alloca %Base*
  %r = alloca i64
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%"Templt#int"* getelementptr (%"Templt#int", %"Templt#int"* null, i32 1) to i64))
  %0 = bitcast i8* %malloccall to %"Templt#int"*
  %1 = getelementptr inbounds %"Templt#int", %"Templt#int"* %0, i32 0, i32 1
  store %"Templt#int_vtable"* @"Templt#int_vatble_loc", %"Templt#int_vtable"** %1
  %2 = getelementptr inbounds %"Templt#int", %"Templt#int"* %0, i32 0, i32 0
  store i64 0, i64* %2
  store %"Templt#int"* %0, %"Templt#int"** %t
  %malloccall.1 = tail call i8* @malloc(i64 ptrtoint (%Base* getelementptr (%Base, %Base* null, i32 1) to i64))
  %3 = bitcast i8* %malloccall.1 to %Base*
  %4 = getelementptr inbounds %Base, %Base* %3, i32 0, i32 1
  store %Base_vtable* @Base_vatble_loc, %Base_vtable** %4
  %5 = getelementptr inbounds %Base, %Base* %3, i32 0, i32 0
  store i64 1, i64* %5
  store %Base* %3, %Base** %b
  %loadvar = load %"Templt#int"*, %"Templt#int"** %t
  %6 = getelementptr inbounds %"Templt#int", %"Templt#int"* %loadvar, i32 0, i32 1
  %7 = load %"Templt#int_vtable"*, %"Templt#int_vtable"** %6
  %8 = getelementptr inbounds %"Templt#int_vtable", %"Templt#int_vtable"* %7, i32 0, i32 2
  %9 = load i64 (%"Templt#int"*, i64)*, i64 (%"Templt#int"*, i64)** %8
  %10 = call i64 %9(%"Templt#int"* %loadvar, i64 2)
  store i64 %10, i64* %r
  %loadvar2 = load %"Templt#int"*, %"Templt#int"** %t
  %11 = getelementptr inbounds %"Templt#int", %"Templt#int"* %loadvar2, i32 0, i32 1
  %12 = load %"Templt#int_vtable"*, %"Templt#int_vtable"** %11
  %13 = getelementptr inbounds %"Templt#int_vtable", %"Templt#int_vtable"* %12, i32 0, i32 1
  %14 = load i64 (%"Templt#int"*)*, i64 (%"Templt#int"*)** %13
  %15 = call i64 %14(%"Templt#int"* %loadvar2)
  %16 = call i64 @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @0, i32 0, i32 0), i64 %15)
  ret i32 0
}

declare noalias i8* @malloc(i64)

declare i64 @printf(i8*, i64)
