; ModuleID = 'my cool mini-java'

%ListMaker_vtable = type { i64* (%ListMaker*)*, i64 (%ListMaker*, i64*)*, i64* (%ListMaker*, i64, i64*)*, i64* (%ListMaker*, i64*, i64)*, i64 (%ListMaker*, i64*)*, i64* (%ListMaker*, i64*, i64)*, i64* (%ListMaker*, i64*, i64)*, i64 (%ListMaker*, i64*, i64)* }
%ListMaker = type { i64, %ListMaker_vtable* }
%Runner_vtable = type { i64* (%Runner*)*, i64 (%Runner*, i64*, i64*, i64, i64*, i64*)* }
%Runner = type { i64, %Runner_vtable* }

@ListMaker_vatble_loc = constant %ListMaker_vtable { i64* (%ListMaker*)* @ListMaker_null_list, i64 (%ListMaker*, i64*)* @ListMaker_is_null_list, i64* (%ListMaker*, i64, i64*)* @ListMaker_link, i64* (%ListMaker*, i64*, i64)* @ListMaker_insert_at_tail, i64 (%ListMaker*, i64*)* @ListMaker_get_len, i64* (%ListMaker*, i64*, i64)* @ListMaker_insert_at_head, i64* (%ListMaker*, i64*, i64)* @ListMaker_after, i64 (%ListMaker*, i64*, i64)* @ListMaker_at }
@0 = private unnamed_addr constant [3 x i8] c"%c\00"
@1 = private unnamed_addr constant [3 x i8] c"%c\00"
@Runner_vatble_loc = constant %Runner_vtable { i64* (%Runner*)* @Runner_load_program, i64 (%Runner*, i64*, i64*, i64, i64*, i64*)* @Runner_run_program }
@2 = private unnamed_addr constant [3 x i8] c"%c\00"
@3 = private unnamed_addr constant [3 x i8] c"%c\00"

define i64* @ListMaker_null_list(%ListMaker*) {
null_list_entry:
  %1 = alloca %ListMaker*
  store %ListMaker* %0, %ListMaker** %1
  %2 = load %ListMaker, %ListMaker* %0
  %3 = alloca %ListMaker
  %m = alloca %ListMaker*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%ListMaker* getelementptr (%ListMaker, %ListMaker* null, i32 1) to i64))
  %4 = bitcast i8* %malloccall to %ListMaker*
  %5 = getelementptr inbounds %ListMaker, %ListMaker* %4, i32 0, i32 1
  store %ListMaker_vtable* @ListMaker_vatble_loc, %ListMaker_vtable** %5
  %6 = getelementptr inbounds %ListMaker, %ListMaker* %4, i32 0, i32 0
  store i64 1, i64* %6
  %7 = ptrtoint %ListMaker** %m to i64
  %8 = add i64 %7, 0
  %9 = inttoptr i64 %8 to %ListMaker**
  store %ListMaker* %4, %ListMaker** %9
  %10 = alloca i64
  store i64 24, i64* %10
  br label %lambdapre

lambdapre:                                        ; preds = %null_list_entry
  %11 = load i64, i64* %10
  %malloccall.1 = tail call i8* @malloc(i64 %11)
  %12 = bitcast i8* %malloccall.1 to i64*
  %13 = ptrtoint i64* %12 to i64
  %14 = add i64 %13, 16
  %15 = inttoptr i64 %14 to %ListMaker**
  %16 = load %ListMaker*, %ListMaker** %m
  store %ListMaker* %16, %ListMaker** %15
  %17 = ptrtoint i64* %12 to i64
  %18 = add i64 %17, 0
  %19 = inttoptr i64 %18 to i64 (i64*)**
  store i64 (i64*)* @4, i64 (i64*)** %19
  ret i64* %12
}

define i64 @ListMaker_is_null_list(%ListMaker*, i64*) {
is_null_list_entry:
  %2 = alloca %ListMaker*
  store %ListMaker* %0, %ListMaker** %2
  %3 = alloca i64*
  store i64* %1, i64** %3
  %4 = load %ListMaker, %ListMaker* %0
  %5 = alloca %ListMaker
  %6 = load i64*, i64** %3
  %7 = ptrtoint i64* %6 to i64
  %8 = add i64 %7, 8
  %9 = inttoptr i64 %8 to i64*
  store i64 2, i64* %9
  %10 = ptrtoint i64* %6 to i64
  %11 = add i64 %10, 0
  %12 = inttoptr i64 %11 to i64 (i64*)**
  %13 = load i64 (i64*)*, i64 (i64*)** %12
  %14 = call i64 %13(i64* %6)
  ret i64 %14
}

define i64* @ListMaker_link(%ListMaker*, i64, i64*) {
link_entry:
  %3 = alloca %ListMaker*
  store %ListMaker* %0, %ListMaker** %3
  %4 = alloca i64
  store i64 %1, i64* %4
  %5 = alloca i64*
  store i64* %2, i64** %5
  %6 = load %ListMaker, %ListMaker* %0
  %7 = alloca %ListMaker
  %8 = alloca i64
  store i64 32, i64* %8
  br label %lambdapre

lambdapre:                                        ; preds = %link_entry
  %9 = load i64, i64* %8
  %malloccall = tail call i8* @malloc(i64 %9)
  %10 = bitcast i8* %malloccall to i64*
  %11 = ptrtoint i64* %10 to i64
  %12 = add i64 %11, 16
  %13 = inttoptr i64 %12 to i64*
  %14 = load i64, i64* %4
  store i64 %14, i64* %13
  %15 = ptrtoint i64* %10 to i64
  %16 = add i64 %15, 24
  %17 = inttoptr i64 %16 to i64**
  %18 = load i64*, i64** %5
  store i64* %18, i64** %17
  %19 = ptrtoint i64* %10 to i64
  %20 = add i64 %19, 0
  %21 = inttoptr i64 %20 to i64 (i64*)**
  store i64 (i64*)* @5, i64 (i64*)** %21
  ret i64* %10
}

define i64* @ListMaker_insert_at_tail(%ListMaker*, i64*, i64) {
insert_at_tail_entry:
  %3 = alloca %ListMaker*
  store %ListMaker* %0, %ListMaker** %3
  %4 = alloca i64*
  store i64* %1, i64** %4
  %5 = alloca i64
  store i64 %2, i64* %5
  %6 = load %ListMaker, %ListMaker* %0
  %7 = alloca %ListMaker
  %m = alloca %ListMaker*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%ListMaker* getelementptr (%ListMaker, %ListMaker* null, i32 1) to i64))
  %8 = bitcast i8* %malloccall to %ListMaker*
  %9 = getelementptr inbounds %ListMaker, %ListMaker* %8, i32 0, i32 1
  store %ListMaker_vtable* @ListMaker_vatble_loc, %ListMaker_vtable** %9
  %10 = getelementptr inbounds %ListMaker, %ListMaker* %8, i32 0, i32 0
  store i64 1, i64* %10
  %11 = ptrtoint %ListMaker** %m to i64
  %12 = add i64 %11, 0
  %13 = inttoptr i64 %12 to %ListMaker**
  store %ListMaker* %8, %ListMaker** %13
  %z = alloca i64*
  %14 = alloca %ListMaker*
  %loadvar = load %ListMaker*, %ListMaker** %m
  %15 = ptrtoint %ListMaker** %14 to i64
  %16 = add i64 %15, 0
  %17 = inttoptr i64 %16 to %ListMaker**
  store %ListMaker* %loadvar, %ListMaker** %17
  %18 = load %ListMaker*, %ListMaker** %14
  %19 = alloca i64*
  %loadvar1 = load i64*, i64** %4
  %20 = ptrtoint i64** %19 to i64
  %21 = add i64 %20, 0
  %22 = inttoptr i64 %21 to i64**
  store i64* %loadvar1, i64** %22
  %23 = load i64*, i64** %19
  %24 = ptrtoint %ListMaker* %18 to i64
  %25 = add i64 %24, 0
  %26 = inttoptr i64 %25 to %ListMaker*
  %27 = getelementptr inbounds %ListMaker, %ListMaker* %26, i32 0, i32 1
  %28 = load %ListMaker_vtable*, %ListMaker_vtable** %27
  %29 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %28, i32 0, i32 1
  %30 = load i64 (%ListMaker*, i64*)*, i64 (%ListMaker*, i64*)** %29
  %31 = call i64 %30(%ListMaker* %18, i64* %23)
  %ultcmptmp = icmp ult i64 0, %31
  %ifcond = icmp ne i1 %ultcmptmp, false
  br i1 %ifcond, label %then, label %else

then:                                             ; preds = %insert_at_tail_entry
  %32 = alloca %ListMaker*
  %loadvar2 = load %ListMaker*, %ListMaker** %m
  %33 = ptrtoint %ListMaker** %32 to i64
  %34 = add i64 %33, 0
  %35 = inttoptr i64 %34 to %ListMaker**
  store %ListMaker* %loadvar2, %ListMaker** %35
  %36 = load %ListMaker*, %ListMaker** %32
  %37 = alloca i64
  %loadvar3 = load i64, i64* %5
  %38 = ptrtoint i64* %37 to i64
  %39 = add i64 %38, 0
  %40 = inttoptr i64 %39 to i64*
  store i64 %loadvar3, i64* %40
  %41 = load i64, i64* %37
  %42 = alloca i64*
  %loadvar4 = load i64*, i64** %4
  %43 = ptrtoint i64** %42 to i64
  %44 = add i64 %43, 0
  %45 = inttoptr i64 %44 to i64**
  store i64* %loadvar4, i64** %45
  %46 = load i64*, i64** %42
  %47 = ptrtoint %ListMaker* %36 to i64
  %48 = add i64 %47, 0
  %49 = inttoptr i64 %48 to %ListMaker*
  %50 = getelementptr inbounds %ListMaker, %ListMaker* %49, i32 0, i32 1
  %51 = load %ListMaker_vtable*, %ListMaker_vtable** %50
  %52 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %51, i32 0, i32 2
  %53 = load i64* (%ListMaker*, i64, i64*)*, i64* (%ListMaker*, i64, i64*)** %52
  %54 = call i64* %53(%ListMaker* %36, i64 %41, i64* %46)
  %55 = ptrtoint i64** %z to i64
  %56 = add i64 %55, 0
  %57 = inttoptr i64 %56 to i64**
  store i64* %54, i64** %57
  br label %ifcont

else:                                             ; preds = %insert_at_tail_entry
  %58 = alloca %ListMaker*
  %loadvar5 = load %ListMaker*, %ListMaker** %m
  %59 = ptrtoint %ListMaker** %58 to i64
  %60 = add i64 %59, 0
  %61 = inttoptr i64 %60 to %ListMaker**
  store %ListMaker* %loadvar5, %ListMaker** %61
  %62 = load %ListMaker*, %ListMaker** %58
  %63 = alloca i64
  %64 = load i64*, i64** %4
  %65 = ptrtoint i64* %64 to i64
  %66 = add i64 %65, 8
  %67 = inttoptr i64 %66 to i64*
  store i64 0, i64* %67
  %68 = ptrtoint i64* %64 to i64
  %69 = add i64 %68, 0
  %70 = inttoptr i64 %69 to i64 (i64*)**
  %71 = load i64 (i64*)*, i64 (i64*)** %70
  %72 = call i64 %71(i64* %64)
  %73 = ptrtoint i64* %63 to i64
  %74 = add i64 %73, 0
  %75 = inttoptr i64 %74 to i64*
  store i64 %72, i64* %75
  %76 = load i64, i64* %63
  %77 = alloca i64*
  %78 = alloca %ListMaker*
  %loadvar6 = load %ListMaker*, %ListMaker** %m
  %79 = ptrtoint %ListMaker** %78 to i64
  %80 = add i64 %79, 0
  %81 = inttoptr i64 %80 to %ListMaker**
  store %ListMaker* %loadvar6, %ListMaker** %81
  %82 = load %ListMaker*, %ListMaker** %78
  %83 = alloca i64*
  %84 = load i64*, i64** %4
  %85 = ptrtoint i64* %84 to i64
  %86 = add i64 %85, 8
  %87 = inttoptr i64 %86 to i64*
  store i64 1, i64* %87
  %88 = ptrtoint i64* %84 to i64
  %89 = add i64 %88, 0
  %90 = inttoptr i64 %89 to i64 (i64*)**
  %91 = load i64 (i64*)*, i64 (i64*)** %90
  %92 = call i64 %91(i64* %84)
  %93 = ptrtoint i64** %83 to i64
  %94 = add i64 %93, 0
  %95 = inttoptr i64 %94 to i64*
  store i64 %92, i64* %95
  %96 = load i64*, i64** %83
  %97 = alloca i64
  %loadvar7 = load i64, i64* %5
  %98 = ptrtoint i64* %97 to i64
  %99 = add i64 %98, 0
  %100 = inttoptr i64 %99 to i64*
  store i64 %loadvar7, i64* %100
  %101 = load i64, i64* %97
  %102 = ptrtoint %ListMaker* %82 to i64
  %103 = add i64 %102, 0
  %104 = inttoptr i64 %103 to %ListMaker*
  %105 = getelementptr inbounds %ListMaker, %ListMaker* %104, i32 0, i32 1
  %106 = load %ListMaker_vtable*, %ListMaker_vtable** %105
  %107 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %106, i32 0, i32 3
  %108 = load i64* (%ListMaker*, i64*, i64)*, i64* (%ListMaker*, i64*, i64)** %107
  %109 = call i64* %108(%ListMaker* %82, i64* %96, i64 %101)
  %110 = ptrtoint i64** %77 to i64
  %111 = add i64 %110, 0
  %112 = inttoptr i64 %111 to i64**
  store i64* %109, i64** %112
  %113 = load i64*, i64** %77
  %114 = ptrtoint %ListMaker* %62 to i64
  %115 = add i64 %114, 0
  %116 = inttoptr i64 %115 to %ListMaker*
  %117 = getelementptr inbounds %ListMaker, %ListMaker* %116, i32 0, i32 1
  %118 = load %ListMaker_vtable*, %ListMaker_vtable** %117
  %119 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %118, i32 0, i32 2
  %120 = load i64* (%ListMaker*, i64, i64*)*, i64* (%ListMaker*, i64, i64*)** %119
  %121 = call i64* %120(%ListMaker* %62, i64 %76, i64* %113)
  %122 = ptrtoint i64** %z to i64
  %123 = add i64 %122, 0
  %124 = inttoptr i64 %123 to i64**
  store i64* %121, i64** %124
  br label %ifcont

ifcont:                                           ; preds = %else, %then
  %loadvar8 = load i64*, i64** %z
  ret i64* %loadvar8
}

define i64 @ListMaker_get_len(%ListMaker*, i64*) {
get_len_entry:
  %2 = alloca %ListMaker*
  store %ListMaker* %0, %ListMaker** %2
  %3 = alloca i64*
  store i64* %1, i64** %3
  %4 = load %ListMaker, %ListMaker* %0
  %5 = alloca %ListMaker
  %m = alloca %ListMaker*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%ListMaker* getelementptr (%ListMaker, %ListMaker* null, i32 1) to i64))
  %6 = bitcast i8* %malloccall to %ListMaker*
  %7 = getelementptr inbounds %ListMaker, %ListMaker* %6, i32 0, i32 1
  store %ListMaker_vtable* @ListMaker_vatble_loc, %ListMaker_vtable** %7
  %8 = getelementptr inbounds %ListMaker, %ListMaker* %6, i32 0, i32 0
  store i64 1, i64* %8
  %9 = ptrtoint %ListMaker** %m to i64
  %10 = add i64 %9, 0
  %11 = inttoptr i64 %10 to %ListMaker**
  store %ListMaker* %6, %ListMaker** %11
  %c = alloca i64
  %12 = alloca %ListMaker*
  %loadvar = load %ListMaker*, %ListMaker** %m
  %13 = ptrtoint %ListMaker** %12 to i64
  %14 = add i64 %13, 0
  %15 = inttoptr i64 %14 to %ListMaker**
  store %ListMaker* %loadvar, %ListMaker** %15
  %16 = load %ListMaker*, %ListMaker** %12
  %17 = alloca i64*
  %loadvar1 = load i64*, i64** %3
  %18 = ptrtoint i64** %17 to i64
  %19 = add i64 %18, 0
  %20 = inttoptr i64 %19 to i64**
  store i64* %loadvar1, i64** %20
  %21 = load i64*, i64** %17
  %22 = ptrtoint %ListMaker* %16 to i64
  %23 = add i64 %22, 0
  %24 = inttoptr i64 %23 to %ListMaker*
  %25 = getelementptr inbounds %ListMaker, %ListMaker* %24, i32 0, i32 1
  %26 = load %ListMaker_vtable*, %ListMaker_vtable** %25
  %27 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %26, i32 0, i32 1
  %28 = load i64 (%ListMaker*, i64*)*, i64 (%ListMaker*, i64*)** %27
  %29 = call i64 %28(%ListMaker* %16, i64* %21)
  %ultcmptmp = icmp ult i64 0, %29
  %ifcond = icmp ne i1 %ultcmptmp, false
  br i1 %ifcond, label %then, label %else

then:                                             ; preds = %get_len_entry
  %30 = ptrtoint i64* %c to i64
  %31 = add i64 %30, 0
  %32 = inttoptr i64 %31 to i64*
  store i64 0, i64* %32
  br label %ifcont

else:                                             ; preds = %get_len_entry
  %33 = alloca %ListMaker*
  %loadvar2 = load %ListMaker*, %ListMaker** %m
  %34 = ptrtoint %ListMaker** %33 to i64
  %35 = add i64 %34, 0
  %36 = inttoptr i64 %35 to %ListMaker**
  store %ListMaker* %loadvar2, %ListMaker** %36
  %37 = load %ListMaker*, %ListMaker** %33
  %38 = alloca i64*
  %39 = load i64*, i64** %3
  %40 = ptrtoint i64* %39 to i64
  %41 = add i64 %40, 8
  %42 = inttoptr i64 %41 to i64*
  store i64 1, i64* %42
  %43 = ptrtoint i64* %39 to i64
  %44 = add i64 %43, 0
  %45 = inttoptr i64 %44 to i64 (i64*)**
  %46 = load i64 (i64*)*, i64 (i64*)** %45
  %47 = call i64 %46(i64* %39)
  %48 = ptrtoint i64** %38 to i64
  %49 = add i64 %48, 0
  %50 = inttoptr i64 %49 to i64*
  store i64 %47, i64* %50
  %51 = load i64*, i64** %38
  %52 = ptrtoint %ListMaker* %37 to i64
  %53 = add i64 %52, 0
  %54 = inttoptr i64 %53 to %ListMaker*
  %55 = getelementptr inbounds %ListMaker, %ListMaker* %54, i32 0, i32 1
  %56 = load %ListMaker_vtable*, %ListMaker_vtable** %55
  %57 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %56, i32 0, i32 4
  %58 = load i64 (%ListMaker*, i64*)*, i64 (%ListMaker*, i64*)** %57
  %59 = call i64 %58(%ListMaker* %37, i64* %51)
  %addtmp = add i64 %59, 1
  %60 = ptrtoint i64* %c to i64
  %61 = add i64 %60, 0
  %62 = inttoptr i64 %61 to i64*
  store i64 %addtmp, i64* %62
  br label %ifcont

ifcont:                                           ; preds = %else, %then
  %loadvar3 = load i64, i64* %c
  ret i64 %loadvar3
}

define i64* @ListMaker_insert_at_head(%ListMaker*, i64*, i64) {
insert_at_head_entry:
  %3 = alloca %ListMaker*
  store %ListMaker* %0, %ListMaker** %3
  %4 = alloca i64*
  store i64* %1, i64** %4
  %5 = alloca i64
  store i64 %2, i64* %5
  %6 = load %ListMaker, %ListMaker* %0
  %7 = alloca %ListMaker
  %m = alloca %ListMaker*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%ListMaker* getelementptr (%ListMaker, %ListMaker* null, i32 1) to i64))
  %8 = bitcast i8* %malloccall to %ListMaker*
  %9 = getelementptr inbounds %ListMaker, %ListMaker* %8, i32 0, i32 1
  store %ListMaker_vtable* @ListMaker_vatble_loc, %ListMaker_vtable** %9
  %10 = getelementptr inbounds %ListMaker, %ListMaker* %8, i32 0, i32 0
  store i64 1, i64* %10
  %11 = ptrtoint %ListMaker** %m to i64
  %12 = add i64 %11, 0
  %13 = inttoptr i64 %12 to %ListMaker**
  store %ListMaker* %8, %ListMaker** %13
  %z = alloca i64*
  %14 = alloca %ListMaker*
  %loadvar = load %ListMaker*, %ListMaker** %m
  %15 = ptrtoint %ListMaker** %14 to i64
  %16 = add i64 %15, 0
  %17 = inttoptr i64 %16 to %ListMaker**
  store %ListMaker* %loadvar, %ListMaker** %17
  %18 = load %ListMaker*, %ListMaker** %14
  %19 = alloca i64
  %loadvar1 = load i64, i64* %5
  %20 = ptrtoint i64* %19 to i64
  %21 = add i64 %20, 0
  %22 = inttoptr i64 %21 to i64*
  store i64 %loadvar1, i64* %22
  %23 = load i64, i64* %19
  %24 = alloca i64*
  %loadvar2 = load i64*, i64** %4
  %25 = ptrtoint i64** %24 to i64
  %26 = add i64 %25, 0
  %27 = inttoptr i64 %26 to i64**
  store i64* %loadvar2, i64** %27
  %28 = load i64*, i64** %24
  %29 = ptrtoint %ListMaker* %18 to i64
  %30 = add i64 %29, 0
  %31 = inttoptr i64 %30 to %ListMaker*
  %32 = getelementptr inbounds %ListMaker, %ListMaker* %31, i32 0, i32 1
  %33 = load %ListMaker_vtable*, %ListMaker_vtable** %32
  %34 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %33, i32 0, i32 2
  %35 = load i64* (%ListMaker*, i64, i64*)*, i64* (%ListMaker*, i64, i64*)** %34
  %36 = call i64* %35(%ListMaker* %18, i64 %23, i64* %28)
  %37 = ptrtoint i64** %z to i64
  %38 = add i64 %37, 0
  %39 = inttoptr i64 %38 to i64**
  store i64* %36, i64** %39
  %loadvar3 = load i64*, i64** %z
  ret i64* %loadvar3
}

define i64* @ListMaker_after(%ListMaker*, i64*, i64) {
after_entry:
  %3 = alloca %ListMaker*
  store %ListMaker* %0, %ListMaker** %3
  %4 = alloca i64*
  store i64* %1, i64** %4
  %5 = alloca i64
  store i64 %2, i64* %5
  %6 = load %ListMaker, %ListMaker* %0
  %7 = alloca %ListMaker
  %m = alloca %ListMaker*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%ListMaker* getelementptr (%ListMaker, %ListMaker* null, i32 1) to i64))
  %8 = bitcast i8* %malloccall to %ListMaker*
  %9 = getelementptr inbounds %ListMaker, %ListMaker* %8, i32 0, i32 1
  store %ListMaker_vtable* @ListMaker_vatble_loc, %ListMaker_vtable** %9
  %10 = getelementptr inbounds %ListMaker, %ListMaker* %8, i32 0, i32 0
  store i64 1, i64* %10
  %11 = ptrtoint %ListMaker** %m to i64
  %12 = add i64 %11, 0
  %13 = inttoptr i64 %12 to %ListMaker**
  store %ListMaker* %8, %ListMaker** %13
  %ans = alloca i64*
  %14 = alloca %ListMaker*
  %loadvar = load %ListMaker*, %ListMaker** %m
  %15 = ptrtoint %ListMaker** %14 to i64
  %16 = add i64 %15, 0
  %17 = inttoptr i64 %16 to %ListMaker**
  store %ListMaker* %loadvar, %ListMaker** %17
  %18 = load %ListMaker*, %ListMaker** %14
  %19 = alloca i64*
  %loadvar1 = load i64*, i64** %4
  %20 = ptrtoint i64** %19 to i64
  %21 = add i64 %20, 0
  %22 = inttoptr i64 %21 to i64**
  store i64* %loadvar1, i64** %22
  %23 = load i64*, i64** %19
  %24 = ptrtoint %ListMaker* %18 to i64
  %25 = add i64 %24, 0
  %26 = inttoptr i64 %25 to %ListMaker*
  %27 = getelementptr inbounds %ListMaker, %ListMaker* %26, i32 0, i32 1
  %28 = load %ListMaker_vtable*, %ListMaker_vtable** %27
  %29 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %28, i32 0, i32 1
  %30 = load i64 (%ListMaker*, i64*)*, i64 (%ListMaker*, i64*)** %29
  %31 = call i64 %30(%ListMaker* %18, i64* %23)
  %ultcmptmp = icmp ult i64 0, %31
  %ifcond = icmp ne i1 %ultcmptmp, false
  br i1 %ifcond, label %then, label %else

then:                                             ; preds = %after_entry
  %loadvar2 = load i64*, i64** %4
  %32 = ptrtoint i64** %ans to i64
  %33 = add i64 %32, 0
  %34 = inttoptr i64 %33 to i64**
  store i64* %loadvar2, i64** %34
  br label %ifcont.11

else:                                             ; preds = %after_entry
  %loadvar3 = load i64, i64* %5
  %ultcmptmp4 = icmp ult i64 %loadvar3, 1
  %ifcond5 = icmp ne i1 %ultcmptmp4, false
  br i1 %ifcond5, label %then6, label %else.8

then6:                                            ; preds = %else
  %loadvar7 = load i64*, i64** %4
  %35 = ptrtoint i64** %ans to i64
  %36 = add i64 %35, 0
  %37 = inttoptr i64 %36 to i64**
  store i64* %loadvar7, i64** %37
  br label %ifcont

else.8:                                           ; preds = %else
  %38 = alloca %ListMaker*
  %loadvar9 = load %ListMaker*, %ListMaker** %m
  %39 = ptrtoint %ListMaker** %38 to i64
  %40 = add i64 %39, 0
  %41 = inttoptr i64 %40 to %ListMaker**
  store %ListMaker* %loadvar9, %ListMaker** %41
  %42 = load %ListMaker*, %ListMaker** %38
  %43 = alloca i64*
  %44 = load i64*, i64** %4
  %45 = ptrtoint i64* %44 to i64
  %46 = add i64 %45, 8
  %47 = inttoptr i64 %46 to i64*
  store i64 1, i64* %47
  %48 = ptrtoint i64* %44 to i64
  %49 = add i64 %48, 0
  %50 = inttoptr i64 %49 to i64 (i64*)**
  %51 = load i64 (i64*)*, i64 (i64*)** %50
  %52 = call i64 %51(i64* %44)
  %53 = ptrtoint i64** %43 to i64
  %54 = add i64 %53, 0
  %55 = inttoptr i64 %54 to i64*
  store i64 %52, i64* %55
  %56 = load i64*, i64** %43
  %57 = alloca i64
  %loadvar10 = load i64, i64* %5
  %addtmp = sub i64 %loadvar10, 1
  %58 = ptrtoint i64* %57 to i64
  %59 = add i64 %58, 0
  %60 = inttoptr i64 %59 to i64*
  store i64 %addtmp, i64* %60
  %61 = load i64, i64* %57
  %62 = ptrtoint %ListMaker* %42 to i64
  %63 = add i64 %62, 0
  %64 = inttoptr i64 %63 to %ListMaker*
  %65 = getelementptr inbounds %ListMaker, %ListMaker* %64, i32 0, i32 1
  %66 = load %ListMaker_vtable*, %ListMaker_vtable** %65
  %67 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %66, i32 0, i32 6
  %68 = load i64* (%ListMaker*, i64*, i64)*, i64* (%ListMaker*, i64*, i64)** %67
  %69 = call i64* %68(%ListMaker* %42, i64* %56, i64 %61)
  %70 = ptrtoint i64** %ans to i64
  %71 = add i64 %70, 0
  %72 = inttoptr i64 %71 to i64**
  store i64* %69, i64** %72
  br label %ifcont

ifcont:                                           ; preds = %else.8, %then6
  br label %ifcont.11

ifcont.11:                                        ; preds = %ifcont, %then
  %loadvar12 = load i64*, i64** %ans
  ret i64* %loadvar12
}

define i64 @ListMaker_at(%ListMaker*, i64*, i64) {
at_entry:
  %3 = alloca %ListMaker*
  store %ListMaker* %0, %ListMaker** %3
  %4 = alloca i64*
  store i64* %1, i64** %4
  %5 = alloca i64
  store i64 %2, i64* %5
  %6 = load %ListMaker, %ListMaker* %0
  %7 = alloca %ListMaker
  %m = alloca %ListMaker*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%ListMaker* getelementptr (%ListMaker, %ListMaker* null, i32 1) to i64))
  %8 = bitcast i8* %malloccall to %ListMaker*
  %9 = getelementptr inbounds %ListMaker, %ListMaker* %8, i32 0, i32 1
  store %ListMaker_vtable* @ListMaker_vatble_loc, %ListMaker_vtable** %9
  %10 = getelementptr inbounds %ListMaker, %ListMaker* %8, i32 0, i32 0
  store i64 1, i64* %10
  %11 = ptrtoint %ListMaker** %m to i64
  %12 = add i64 %11, 0
  %13 = inttoptr i64 %12 to %ListMaker**
  store %ListMaker* %8, %ListMaker** %13
  %afterx = alloca i64*
  %14 = alloca %ListMaker*
  %loadvar = load %ListMaker*, %ListMaker** %m
  %15 = ptrtoint %ListMaker** %14 to i64
  %16 = add i64 %15, 0
  %17 = inttoptr i64 %16 to %ListMaker**
  store %ListMaker* %loadvar, %ListMaker** %17
  %18 = load %ListMaker*, %ListMaker** %14
  %19 = alloca i64*
  %loadvar1 = load i64*, i64** %4
  %20 = ptrtoint i64** %19 to i64
  %21 = add i64 %20, 0
  %22 = inttoptr i64 %21 to i64**
  store i64* %loadvar1, i64** %22
  %23 = load i64*, i64** %19
  %24 = alloca i64
  %loadvar2 = load i64, i64* %5
  %25 = ptrtoint i64* %24 to i64
  %26 = add i64 %25, 0
  %27 = inttoptr i64 %26 to i64*
  store i64 %loadvar2, i64* %27
  %28 = load i64, i64* %24
  %29 = ptrtoint %ListMaker* %18 to i64
  %30 = add i64 %29, 0
  %31 = inttoptr i64 %30 to %ListMaker*
  %32 = getelementptr inbounds %ListMaker, %ListMaker* %31, i32 0, i32 1
  %33 = load %ListMaker_vtable*, %ListMaker_vtable** %32
  %34 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %33, i32 0, i32 6
  %35 = load i64* (%ListMaker*, i64*, i64)*, i64* (%ListMaker*, i64*, i64)** %34
  %36 = call i64* %35(%ListMaker* %18, i64* %23, i64 %28)
  %37 = ptrtoint i64** %afterx to i64
  %38 = add i64 %37, 0
  %39 = inttoptr i64 %38 to i64**
  store i64* %36, i64** %39
  %40 = load i64*, i64** %afterx
  %41 = ptrtoint i64* %40 to i64
  %42 = add i64 %41, 8
  %43 = inttoptr i64 %42 to i64*
  store i64 0, i64* %43
  %44 = ptrtoint i64* %40 to i64
  %45 = add i64 %44, 0
  %46 = inttoptr i64 %45 to i64 (i64*)**
  %47 = load i64 (i64*)*, i64 (i64*)** %46
  %48 = call i64 %47(i64* %40)
  ret i64 %48
}

declare noalias i8* @malloc(i64)

define i64 @4(i64*) {
loaddata:
  %1 = alloca i64*
  store i64* %0, i64** %1
  %2 = load i64*, i64** %1
  %3 = ptrtoint i64* %2 to i64
  %4 = add i64 %3, 8
  %5 = inttoptr i64 %4 to i64*
  %6 = ptrtoint i64* %2 to i64
  %7 = add i64 %6, 16
  %8 = inttoptr i64 %7 to %ListMaker**
  br label %funcstmt

funcstmt:                                         ; preds = %loaddata
  %c = alloca i64
  %loadvar = load i64, i64* %5
  %ultcmptmp = icmp ult i64 1, %loadvar
  %ifcond = icmp ne i1 %ultcmptmp, false
  br i1 %ifcond, label %then, label %else

then:                                             ; preds = %funcstmt
  %9 = ptrtoint i64* %c to i64
  %10 = add i64 %9, 0
  %11 = inttoptr i64 %10 to i64*
  store i64 1, i64* %11
  br label %ifcont.7

else:                                             ; preds = %funcstmt
  %loadvar1 = load i64, i64* %5
  %ultcmptmp2 = icmp ult i64 %loadvar1, 1
  %ifcond3 = icmp ne i1 %ultcmptmp2, false
  br i1 %ifcond3, label %then4, label %else.5

then4:                                            ; preds = %else
  %12 = ptrtoint i64* %c to i64
  %13 = add i64 %12, 0
  %14 = inttoptr i64 %13 to i64*
  store i64 0, i64* %14
  br label %ifcont

else.5:                                           ; preds = %else
  %15 = alloca %ListMaker*
  %loadvar6 = load %ListMaker*, %ListMaker** %8
  %16 = ptrtoint %ListMaker** %15 to i64
  %17 = add i64 %16, 0
  %18 = inttoptr i64 %17 to %ListMaker**
  store %ListMaker* %loadvar6, %ListMaker** %18
  %19 = load %ListMaker*, %ListMaker** %15
  %20 = ptrtoint %ListMaker* %19 to i64
  %21 = add i64 %20, 0
  %22 = inttoptr i64 %21 to %ListMaker*
  %23 = getelementptr inbounds %ListMaker, %ListMaker* %22, i32 0, i32 1
  %24 = load %ListMaker_vtable*, %ListMaker_vtable** %23
  %25 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %24, i32 0, i32 0
  %26 = load i64* (%ListMaker*)*, i64* (%ListMaker*)** %25
  %27 = call i64* %26(%ListMaker* %19)
  %28 = ptrtoint i64* %c to i64
  %29 = add i64 %28, 0
  %30 = inttoptr i64 %29 to i64**
  store i64* %27, i64** %30
  br label %ifcont

ifcont:                                           ; preds = %else.5, %then4
  br label %ifcont.7

ifcont.7:                                         ; preds = %ifcont, %then
  %loadvar8 = load i64, i64* %c
  %31 = alloca i64
  store i64 %loadvar8, i64* %31
  %32 = ptrtoint i64* %31 to i64
  %33 = inttoptr i64 %32 to i64*
  %34 = load i64, i64* %33
  ret i64 %34
}

define i64 @5(i64*) {
loaddata:
  %1 = alloca i64*
  store i64* %0, i64** %1
  %2 = load i64*, i64** %1
  %3 = ptrtoint i64* %2 to i64
  %4 = add i64 %3, 8
  %5 = inttoptr i64 %4 to i64*
  %6 = ptrtoint i64* %2 to i64
  %7 = add i64 %6, 16
  %8 = inttoptr i64 %7 to i64*
  %9 = ptrtoint i64* %2 to i64
  %10 = add i64 %9, 24
  %11 = inttoptr i64 %10 to i64**
  br label %funcstmt

funcstmt:                                         ; preds = %loaddata
  %c = alloca i64
  %loadvar = load i64, i64* %5
  %ultcmptmp = icmp ult i64 1, %loadvar
  %ifcond = icmp ne i1 %ultcmptmp, false
  br i1 %ifcond, label %then, label %else

then:                                             ; preds = %funcstmt
  %12 = ptrtoint i64* %c to i64
  %13 = add i64 %12, 0
  %14 = inttoptr i64 %13 to i64*
  store i64 0, i64* %14
  br label %ifcont.8

else:                                             ; preds = %funcstmt
  %loadvar1 = load i64, i64* %5
  %ultcmptmp2 = icmp ult i64 %loadvar1, 1
  %ifcond3 = icmp ne i1 %ultcmptmp2, false
  br i1 %ifcond3, label %then4, label %else.6

then4:                                            ; preds = %else
  %loadvar5 = load i64, i64* %8
  %15 = ptrtoint i64* %c to i64
  %16 = add i64 %15, 0
  %17 = inttoptr i64 %16 to i64*
  store i64 %loadvar5, i64* %17
  br label %ifcont

else.6:                                           ; preds = %else
  %loadvar7 = load i64*, i64** %11
  %18 = ptrtoint i64* %c to i64
  %19 = add i64 %18, 0
  %20 = inttoptr i64 %19 to i64**
  store i64* %loadvar7, i64** %20
  br label %ifcont

ifcont:                                           ; preds = %else.6, %then4
  br label %ifcont.8

ifcont.8:                                         ; preds = %ifcont, %then
  %loadvar9 = load i64, i64* %c
  %21 = alloca i64
  store i64 %loadvar9, i64* %21
  %22 = ptrtoint i64* %21 to i64
  %23 = inttoptr i64 %22 to i64*
  %24 = load i64, i64* %23
  ret i64 %24
}

define i64* @Runner_load_program(%Runner*) {
load_program_entry:
  %1 = alloca %Runner*
  store %Runner* %0, %Runner** %1
  %2 = load %Runner, %Runner* %0
  %3 = alloca %Runner
  %m = alloca %ListMaker*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%ListMaker* getelementptr (%ListMaker, %ListMaker* null, i32 1) to i64))
  %4 = bitcast i8* %malloccall to %ListMaker*
  %5 = getelementptr inbounds %ListMaker, %ListMaker* %4, i32 0, i32 1
  store %ListMaker_vtable* @ListMaker_vatble_loc, %ListMaker_vtable** %5
  %6 = getelementptr inbounds %ListMaker, %ListMaker* %4, i32 0, i32 0
  store i64 1, i64* %6
  %7 = ptrtoint %ListMaker** %m to i64
  %8 = add i64 %7, 0
  %9 = inttoptr i64 %8 to %ListMaker**
  store %ListMaker* %4, %ListMaker** %9
  %c = alloca i64*
  %a = alloca i64
  %10 = alloca %ListMaker*
  %loadvar = load %ListMaker*, %ListMaker** %m
  %11 = ptrtoint %ListMaker** %10 to i64
  %12 = add i64 %11, 0
  %13 = inttoptr i64 %12 to %ListMaker**
  store %ListMaker* %loadvar, %ListMaker** %13
  %14 = load %ListMaker*, %ListMaker** %10
  %15 = ptrtoint %ListMaker* %14 to i64
  %16 = add i64 %15, 0
  %17 = inttoptr i64 %16 to %ListMaker*
  %18 = getelementptr inbounds %ListMaker, %ListMaker* %17, i32 0, i32 1
  %19 = load %ListMaker_vtable*, %ListMaker_vtable** %18
  %20 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %19, i32 0, i32 0
  %21 = load i64* (%ListMaker*)*, i64* (%ListMaker*)** %20
  %22 = call i64* %21(%ListMaker* %14)
  %23 = ptrtoint i64** %c to i64
  %24 = add i64 %23, 0
  %25 = inttoptr i64 %24 to i64**
  store i64* %22, i64** %25
  %26 = alloca i64
  store i64 0, i64* %26
  %27 = call i64 @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i64* %26)
  %28 = load i64, i64* %26
  %29 = ptrtoint i64* %a to i64
  %30 = add i64 %29, 0
  %31 = inttoptr i64 %30 to i64*
  store i64 %28, i64* %31
  %loadvar1 = load i64, i64* %a
  %ultcmptmp = icmp ne i64 %loadvar1, 10
  %whilefirstcondexpr = icmp ne i1 %ultcmptmp, false
  br i1 %whilefirstcondexpr, label %whilebody, label %afterloop

whilebody:                                        ; preds = %whilebody, %load_program_entry
  %32 = alloca %ListMaker*
  %loadvar2 = load %ListMaker*, %ListMaker** %m
  %33 = ptrtoint %ListMaker** %32 to i64
  %34 = add i64 %33, 0
  %35 = inttoptr i64 %34 to %ListMaker**
  store %ListMaker* %loadvar2, %ListMaker** %35
  %36 = load %ListMaker*, %ListMaker** %32
  %37 = alloca i64*
  %loadvar3 = load i64*, i64** %c
  %38 = ptrtoint i64** %37 to i64
  %39 = add i64 %38, 0
  %40 = inttoptr i64 %39 to i64**
  store i64* %loadvar3, i64** %40
  %41 = load i64*, i64** %37
  %42 = alloca i64
  %loadvar4 = load i64, i64* %a
  %43 = ptrtoint i64* %42 to i64
  %44 = add i64 %43, 0
  %45 = inttoptr i64 %44 to i64*
  store i64 %loadvar4, i64* %45
  %46 = load i64, i64* %42
  %47 = ptrtoint %ListMaker* %36 to i64
  %48 = add i64 %47, 0
  %49 = inttoptr i64 %48 to %ListMaker*
  %50 = getelementptr inbounds %ListMaker, %ListMaker* %49, i32 0, i32 1
  %51 = load %ListMaker_vtable*, %ListMaker_vtable** %50
  %52 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %51, i32 0, i32 3
  %53 = load i64* (%ListMaker*, i64*, i64)*, i64* (%ListMaker*, i64*, i64)** %52
  %54 = call i64* %53(%ListMaker* %36, i64* %41, i64 %46)
  %55 = ptrtoint i64** %c to i64
  %56 = add i64 %55, 0
  %57 = inttoptr i64 %56 to i64**
  store i64* %54, i64** %57
  %58 = alloca i64
  store i64 0, i64* %58
  %59 = call i64 @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0), i64* %58)
  %60 = load i64, i64* %58
  %61 = ptrtoint i64* %a to i64
  %62 = add i64 %61, 0
  %63 = inttoptr i64 %62 to i64*
  store i64 %60, i64* %63
  %loadvar5 = load i64, i64* %a
  %ultcmptmp6 = icmp ne i64 %loadvar5, 10
  %whileloopcondexpr = icmp ne i1 %ultcmptmp6, false
  br i1 %whileloopcondexpr, label %whilebody, label %afterloop

afterloop:                                        ; preds = %whilebody, %load_program_entry
  %loadvar7 = load i64*, i64** %c
  ret i64* %loadvar7
}

define i64 @Runner_run_program(%Runner*, i64*, i64*, i64, i64*, i64*) {
run_program_entry:
  %6 = alloca %Runner*
  store %Runner* %0, %Runner** %6
  %7 = alloca i64*
  store i64* %1, i64** %7
  %8 = alloca i64*
  store i64* %2, i64** %8
  %9 = alloca i64
  store i64 %3, i64* %9
  %10 = alloca i64*
  store i64* %4, i64** %10
  %11 = alloca i64*
  store i64* %5, i64** %11
  %12 = load %Runner, %Runner* %0
  %13 = alloca %Runner
  %c = alloca i64
  %m = alloca %ListMaker*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%ListMaker* getelementptr (%ListMaker, %ListMaker* null, i32 1) to i64))
  %14 = bitcast i8* %malloccall to %ListMaker*
  %15 = getelementptr inbounds %ListMaker, %ListMaker* %14, i32 0, i32 1
  store %ListMaker_vtable* @ListMaker_vatble_loc, %ListMaker_vtable** %15
  %16 = getelementptr inbounds %ListMaker, %ListMaker* %14, i32 0, i32 0
  store i64 1, i64* %16
  %17 = ptrtoint %ListMaker** %m to i64
  %18 = add i64 %17, 0
  %19 = inttoptr i64 %18 to %ListMaker**
  store %ListMaker* %14, %ListMaker** %19
  %r = alloca %Runner*
  %malloccall.1 = tail call i8* @malloc(i64 ptrtoint (%Runner* getelementptr (%Runner, %Runner* null, i32 1) to i64))
  %20 = bitcast i8* %malloccall.1 to %Runner*
  %21 = getelementptr inbounds %Runner, %Runner* %20, i32 0, i32 1
  store %Runner_vtable* @Runner_vatble_loc, %Runner_vtable** %21
  %22 = getelementptr inbounds %Runner, %Runner* %20, i32 0, i32 0
  store i64 2, i64* %22
  %23 = ptrtoint %Runner** %r to i64
  %24 = add i64 %23, 0
  %25 = inttoptr i64 %24 to %Runner**
  store %Runner* %20, %Runner** %25
  %26 = load i64*, i64** %7
  %27 = ptrtoint i64* %26 to i64
  %28 = add i64 %27, 8
  %29 = inttoptr i64 %28 to i64*
  store i64 2, i64* %29
  %30 = ptrtoint i64* %26 to i64
  %31 = add i64 %30, 0
  %32 = inttoptr i64 %31 to i64 (i64*)**
  %33 = load i64 (i64*)*, i64 (i64*)** %32
  %34 = call i64 %33(i64* %26)
  %ultcmptmp = icmp eq i64 %34, 1
  %ifcond = icmp ne i1 %ultcmptmp, false
  br i1 %ifcond, label %then, label %else

then:                                             ; preds = %run_program_entry
  %35 = ptrtoint i64* %c to i64
  %36 = add i64 %35, 0
  %37 = inttoptr i64 %36 to i64*
  store i64 0, i64* %37
  br label %ifcont

else:                                             ; preds = %run_program_entry
  %38 = ptrtoint i64* %c to i64
  %39 = add i64 %38, 0
  %40 = inttoptr i64 %39 to i64*
  store i64 0, i64* %40
  br label %ifcont

ifcont:                                           ; preds = %else, %then
  %41 = load i64*, i64** %7
  %42 = ptrtoint i64* %41 to i64
  %43 = add i64 %42, 8
  %44 = inttoptr i64 %43 to i64*
  store i64 0, i64* %44
  %45 = ptrtoint i64* %41 to i64
  %46 = add i64 %45, 0
  %47 = inttoptr i64 %46 to i64 (i64*)**
  %48 = load i64 (i64*)*, i64 (i64*)** %47
  %49 = call i64 %48(i64* %41)
  %ultcmptmp2 = icmp eq i64 %49, 93
  %ifcond3 = icmp ne i1 %ultcmptmp2, false
  br i1 %ifcond3, label %then4, label %else.18

then4:                                            ; preds = %ifcont
  %loadvar = load i64, i64* %9
  %ultcmptmp5 = icmp eq i64 %loadvar, 0
  %ifcond6 = icmp ne i1 %ultcmptmp5, false
  br i1 %ifcond6, label %then7, label %else.12

then7:                                            ; preds = %then4
  %50 = alloca %Runner*
  %loadvar8 = load %Runner*, %Runner** %r
  %51 = ptrtoint %Runner** %50 to i64
  %52 = add i64 %51, 0
  %53 = inttoptr i64 %52 to %Runner**
  store %Runner* %loadvar8, %Runner** %53
  %54 = load %Runner*, %Runner** %50
  %55 = alloca i64*
  %56 = load i64*, i64** %7
  %57 = ptrtoint i64* %56 to i64
  %58 = add i64 %57, 8
  %59 = inttoptr i64 %58 to i64*
  store i64 1, i64* %59
  %60 = ptrtoint i64* %56 to i64
  %61 = add i64 %60, 0
  %62 = inttoptr i64 %61 to i64 (i64*)**
  %63 = load i64 (i64*)*, i64 (i64*)** %62
  %64 = call i64 %63(i64* %56)
  %65 = ptrtoint i64** %55 to i64
  %66 = add i64 %65, 0
  %67 = inttoptr i64 %66 to i64*
  store i64 %64, i64* %67
  %68 = load i64*, i64** %55
  %69 = alloca i64*
  %loadvar9 = load i64*, i64** %8
  %70 = ptrtoint i64** %69 to i64
  %71 = add i64 %70, 0
  %72 = inttoptr i64 %71 to i64**
  store i64* %loadvar9, i64** %72
  %73 = load i64*, i64** %69
  %74 = alloca i64
  %loadvar10 = load i64, i64* %9
  %75 = ptrtoint i64* %74 to i64
  %76 = add i64 %75, 0
  %77 = inttoptr i64 %76 to i64*
  store i64 %loadvar10, i64* %77
  %78 = load i64, i64* %74
  %79 = alloca i64*
  %loadvar11 = load i64*, i64** %10
  %80 = ptrtoint i64** %79 to i64
  %81 = add i64 %80, 0
  %82 = inttoptr i64 %81 to i64**
  store i64* %loadvar11, i64** %82
  %83 = load i64*, i64** %79
  %84 = alloca i64*
  %85 = load i64*, i64** %11
  %86 = ptrtoint i64* %85 to i64
  %87 = add i64 %86, 8
  %88 = inttoptr i64 %87 to i64*
  store i64 1, i64* %88
  %89 = ptrtoint i64* %85 to i64
  %90 = add i64 %89, 0
  %91 = inttoptr i64 %90 to i64 (i64*)**
  %92 = load i64 (i64*)*, i64 (i64*)** %91
  %93 = call i64 %92(i64* %85)
  %94 = ptrtoint i64** %84 to i64
  %95 = add i64 %94, 0
  %96 = inttoptr i64 %95 to i64*
  store i64 %93, i64* %96
  %97 = load i64*, i64** %84
  %98 = ptrtoint %Runner* %54 to i64
  %99 = add i64 %98, 0
  %100 = inttoptr i64 %99 to %Runner*
  %101 = getelementptr inbounds %Runner, %Runner* %100, i32 0, i32 1
  %102 = load %Runner_vtable*, %Runner_vtable** %101
  %103 = getelementptr inbounds %Runner_vtable, %Runner_vtable* %102, i32 0, i32 1
  %104 = load i64 (%Runner*, i64*, i64*, i64, i64*, i64*)*, i64 (%Runner*, i64*, i64*, i64, i64*, i64*)** %103
  %105 = call i64 %104(%Runner* %54, i64* %68, i64* %73, i64 %78, i64* %83, i64* %97)
  %106 = ptrtoint i64* %c to i64
  %107 = add i64 %106, 0
  %108 = inttoptr i64 %107 to i64*
  store i64 %105, i64* %108
  br label %ifcont.17

else.12:                                          ; preds = %then4
  %109 = alloca %Runner*
  %loadvar13 = load %Runner*, %Runner** %r
  %110 = ptrtoint %Runner** %109 to i64
  %111 = add i64 %110, 0
  %112 = inttoptr i64 %111 to %Runner**
  store %Runner* %loadvar13, %Runner** %112
  %113 = load %Runner*, %Runner** %109
  %114 = alloca i64*
  %115 = load i64*, i64** %11
  %116 = ptrtoint i64* %115 to i64
  %117 = add i64 %116, 8
  %118 = inttoptr i64 %117 to i64*
  store i64 0, i64* %118
  %119 = ptrtoint i64* %115 to i64
  %120 = add i64 %119, 0
  %121 = inttoptr i64 %120 to i64 (i64*)**
  %122 = load i64 (i64*)*, i64 (i64*)** %121
  %123 = call i64 %122(i64* %115)
  %124 = ptrtoint i64** %114 to i64
  %125 = add i64 %124, 0
  %126 = inttoptr i64 %125 to i64*
  store i64 %123, i64* %126
  %127 = load i64*, i64** %114
  %128 = alloca i64*
  %loadvar14 = load i64*, i64** %8
  %129 = ptrtoint i64** %128 to i64
  %130 = add i64 %129, 0
  %131 = inttoptr i64 %130 to i64**
  store i64* %loadvar14, i64** %131
  %132 = load i64*, i64** %128
  %133 = alloca i64
  %loadvar15 = load i64, i64* %9
  %134 = ptrtoint i64* %133 to i64
  %135 = add i64 %134, 0
  %136 = inttoptr i64 %135 to i64*
  store i64 %loadvar15, i64* %136
  %137 = load i64, i64* %133
  %138 = alloca i64*
  %loadvar16 = load i64*, i64** %10
  %139 = ptrtoint i64** %138 to i64
  %140 = add i64 %139, 0
  %141 = inttoptr i64 %140 to i64**
  store i64* %loadvar16, i64** %141
  %142 = load i64*, i64** %138
  %143 = alloca i64*
  %144 = load i64*, i64** %11
  %145 = ptrtoint i64* %144 to i64
  %146 = add i64 %145, 8
  %147 = inttoptr i64 %146 to i64*
  store i64 1, i64* %147
  %148 = ptrtoint i64* %144 to i64
  %149 = add i64 %148, 0
  %150 = inttoptr i64 %149 to i64 (i64*)**
  %151 = load i64 (i64*)*, i64 (i64*)** %150
  %152 = call i64 %151(i64* %144)
  %153 = ptrtoint i64** %143 to i64
  %154 = add i64 %153, 0
  %155 = inttoptr i64 %154 to i64*
  store i64 %152, i64* %155
  %156 = load i64*, i64** %143
  %157 = ptrtoint %Runner* %113 to i64
  %158 = add i64 %157, 0
  %159 = inttoptr i64 %158 to %Runner*
  %160 = getelementptr inbounds %Runner, %Runner* %159, i32 0, i32 1
  %161 = load %Runner_vtable*, %Runner_vtable** %160
  %162 = getelementptr inbounds %Runner_vtable, %Runner_vtable* %161, i32 0, i32 1
  %163 = load i64 (%Runner*, i64*, i64*, i64, i64*, i64*)*, i64 (%Runner*, i64*, i64*, i64, i64*, i64*)** %162
  %164 = call i64 %163(%Runner* %113, i64* %127, i64* %132, i64 %137, i64* %142, i64* %156)
  %165 = ptrtoint i64* %c to i64
  %166 = add i64 %165, 0
  %167 = inttoptr i64 %166 to i64*
  store i64 %164, i64* %167
  br label %ifcont.17

ifcont.17:                                        ; preds = %else.12, %then7
  br label %ifcont.19

else.18:                                          ; preds = %ifcont
  %168 = ptrtoint i64* %c to i64
  %169 = add i64 %168, 0
  %170 = inttoptr i64 %169 to i64*
  store i64 0, i64* %170
  br label %ifcont.19

ifcont.19:                                        ; preds = %else.18, %ifcont.17
  %171 = load i64*, i64** %7
  %172 = ptrtoint i64* %171 to i64
  %173 = add i64 %172, 8
  %174 = inttoptr i64 %173 to i64*
  store i64 0, i64* %174
  %175 = ptrtoint i64* %171 to i64
  %176 = add i64 %175, 0
  %177 = inttoptr i64 %176 to i64 (i64*)**
  %178 = load i64 (i64*)*, i64 (i64*)** %177
  %179 = call i64 %178(i64* %171)
  %ultcmptmp20 = icmp eq i64 %179, 62
  %ifcond21 = icmp ne i1 %ultcmptmp20, false
  br i1 %ifcond21, label %then22, label %else.28

then22:                                           ; preds = %ifcont.19
  %180 = alloca %Runner*
  %loadvar23 = load %Runner*, %Runner** %r
  %181 = ptrtoint %Runner** %180 to i64
  %182 = add i64 %181, 0
  %183 = inttoptr i64 %182 to %Runner**
  store %Runner* %loadvar23, %Runner** %183
  %184 = load %Runner*, %Runner** %180
  %185 = alloca i64*
  %186 = load i64*, i64** %7
  %187 = ptrtoint i64* %186 to i64
  %188 = add i64 %187, 8
  %189 = inttoptr i64 %188 to i64*
  store i64 1, i64* %189
  %190 = ptrtoint i64* %186 to i64
  %191 = add i64 %190, 0
  %192 = inttoptr i64 %191 to i64 (i64*)**
  %193 = load i64 (i64*)*, i64 (i64*)** %192
  %194 = call i64 %193(i64* %186)
  %195 = ptrtoint i64** %185 to i64
  %196 = add i64 %195, 0
  %197 = inttoptr i64 %196 to i64*
  store i64 %194, i64* %197
  %198 = load i64*, i64** %185
  %199 = alloca i64*
  %200 = alloca %ListMaker*
  %loadvar24 = load %ListMaker*, %ListMaker** %m
  %201 = ptrtoint %ListMaker** %200 to i64
  %202 = add i64 %201, 0
  %203 = inttoptr i64 %202 to %ListMaker**
  store %ListMaker* %loadvar24, %ListMaker** %203
  %204 = load %ListMaker*, %ListMaker** %200
  %205 = alloca i64
  %loadvar25 = load i64, i64* %9
  %206 = ptrtoint i64* %205 to i64
  %207 = add i64 %206, 0
  %208 = inttoptr i64 %207 to i64*
  store i64 %loadvar25, i64* %208
  %209 = load i64, i64* %205
  %210 = alloca i64*
  %loadvar26 = load i64*, i64** %8
  %211 = ptrtoint i64** %210 to i64
  %212 = add i64 %211, 0
  %213 = inttoptr i64 %212 to i64**
  store i64* %loadvar26, i64** %213
  %214 = load i64*, i64** %210
  %215 = ptrtoint %ListMaker* %204 to i64
  %216 = add i64 %215, 0
  %217 = inttoptr i64 %216 to %ListMaker*
  %218 = getelementptr inbounds %ListMaker, %ListMaker* %217, i32 0, i32 1
  %219 = load %ListMaker_vtable*, %ListMaker_vtable** %218
  %220 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %219, i32 0, i32 2
  %221 = load i64* (%ListMaker*, i64, i64*)*, i64* (%ListMaker*, i64, i64*)** %220
  %222 = call i64* %221(%ListMaker* %204, i64 %209, i64* %214)
  %223 = ptrtoint i64** %199 to i64
  %224 = add i64 %223, 0
  %225 = inttoptr i64 %224 to i64**
  store i64* %222, i64** %225
  %226 = load i64*, i64** %199
  %227 = alloca i64
  %228 = load i64*, i64** %10
  %229 = ptrtoint i64* %228 to i64
  %230 = add i64 %229, 8
  %231 = inttoptr i64 %230 to i64*
  store i64 0, i64* %231
  %232 = ptrtoint i64* %228 to i64
  %233 = add i64 %232, 0
  %234 = inttoptr i64 %233 to i64 (i64*)**
  %235 = load i64 (i64*)*, i64 (i64*)** %234
  %236 = call i64 %235(i64* %228)
  %237 = ptrtoint i64* %227 to i64
  %238 = add i64 %237, 0
  %239 = inttoptr i64 %238 to i64*
  store i64 %236, i64* %239
  %240 = load i64, i64* %227
  %241 = alloca i64*
  %242 = load i64*, i64** %10
  %243 = ptrtoint i64* %242 to i64
  %244 = add i64 %243, 8
  %245 = inttoptr i64 %244 to i64*
  store i64 1, i64* %245
  %246 = ptrtoint i64* %242 to i64
  %247 = add i64 %246, 0
  %248 = inttoptr i64 %247 to i64 (i64*)**
  %249 = load i64 (i64*)*, i64 (i64*)** %248
  %250 = call i64 %249(i64* %242)
  %251 = ptrtoint i64** %241 to i64
  %252 = add i64 %251, 0
  %253 = inttoptr i64 %252 to i64*
  store i64 %250, i64* %253
  %254 = load i64*, i64** %241
  %255 = alloca i64*
  %loadvar27 = load i64*, i64** %11
  %256 = ptrtoint i64** %255 to i64
  %257 = add i64 %256, 0
  %258 = inttoptr i64 %257 to i64**
  store i64* %loadvar27, i64** %258
  %259 = load i64*, i64** %255
  %260 = ptrtoint %Runner* %184 to i64
  %261 = add i64 %260, 0
  %262 = inttoptr i64 %261 to %Runner*
  %263 = getelementptr inbounds %Runner, %Runner* %262, i32 0, i32 1
  %264 = load %Runner_vtable*, %Runner_vtable** %263
  %265 = getelementptr inbounds %Runner_vtable, %Runner_vtable* %264, i32 0, i32 1
  %266 = load i64 (%Runner*, i64*, i64*, i64, i64*, i64*)*, i64 (%Runner*, i64*, i64*, i64, i64*, i64*)** %265
  %267 = call i64 %266(%Runner* %184, i64* %198, i64* %226, i64 %240, i64* %254, i64* %259)
  %268 = ptrtoint i64* %c to i64
  %269 = add i64 %268, 0
  %270 = inttoptr i64 %269 to i64*
  store i64 %267, i64* %270
  br label %ifcont.29

else.28:                                          ; preds = %ifcont.19
  %271 = ptrtoint i64* %c to i64
  %272 = add i64 %271, 0
  %273 = inttoptr i64 %272 to i64*
  store i64 0, i64* %273
  br label %ifcont.29

ifcont.29:                                        ; preds = %else.28, %then22
  %274 = load i64*, i64** %7
  %275 = ptrtoint i64* %274 to i64
  %276 = add i64 %275, 8
  %277 = inttoptr i64 %276 to i64*
  store i64 0, i64* %277
  %278 = ptrtoint i64* %274 to i64
  %279 = add i64 %278, 0
  %280 = inttoptr i64 %279 to i64 (i64*)**
  %281 = load i64 (i64*)*, i64 (i64*)** %280
  %282 = call i64 %281(i64* %274)
  %ultcmptmp30 = icmp eq i64 %282, 60
  %ifcond31 = icmp ne i1 %ultcmptmp30, false
  br i1 %ifcond31, label %then32, label %else.38

then32:                                           ; preds = %ifcont.29
  %283 = alloca %Runner*
  %loadvar33 = load %Runner*, %Runner** %r
  %284 = ptrtoint %Runner** %283 to i64
  %285 = add i64 %284, 0
  %286 = inttoptr i64 %285 to %Runner**
  store %Runner* %loadvar33, %Runner** %286
  %287 = load %Runner*, %Runner** %283
  %288 = alloca i64*
  %289 = load i64*, i64** %7
  %290 = ptrtoint i64* %289 to i64
  %291 = add i64 %290, 8
  %292 = inttoptr i64 %291 to i64*
  store i64 1, i64* %292
  %293 = ptrtoint i64* %289 to i64
  %294 = add i64 %293, 0
  %295 = inttoptr i64 %294 to i64 (i64*)**
  %296 = load i64 (i64*)*, i64 (i64*)** %295
  %297 = call i64 %296(i64* %289)
  %298 = ptrtoint i64** %288 to i64
  %299 = add i64 %298, 0
  %300 = inttoptr i64 %299 to i64*
  store i64 %297, i64* %300
  %301 = load i64*, i64** %288
  %302 = alloca i64*
  %303 = load i64*, i64** %8
  %304 = ptrtoint i64* %303 to i64
  %305 = add i64 %304, 8
  %306 = inttoptr i64 %305 to i64*
  store i64 1, i64* %306
  %307 = ptrtoint i64* %303 to i64
  %308 = add i64 %307, 0
  %309 = inttoptr i64 %308 to i64 (i64*)**
  %310 = load i64 (i64*)*, i64 (i64*)** %309
  %311 = call i64 %310(i64* %303)
  %312 = ptrtoint i64** %302 to i64
  %313 = add i64 %312, 0
  %314 = inttoptr i64 %313 to i64*
  store i64 %311, i64* %314
  %315 = load i64*, i64** %302
  %316 = alloca i64
  %317 = load i64*, i64** %8
  %318 = ptrtoint i64* %317 to i64
  %319 = add i64 %318, 8
  %320 = inttoptr i64 %319 to i64*
  store i64 0, i64* %320
  %321 = ptrtoint i64* %317 to i64
  %322 = add i64 %321, 0
  %323 = inttoptr i64 %322 to i64 (i64*)**
  %324 = load i64 (i64*)*, i64 (i64*)** %323
  %325 = call i64 %324(i64* %317)
  %326 = ptrtoint i64* %316 to i64
  %327 = add i64 %326, 0
  %328 = inttoptr i64 %327 to i64*
  store i64 %325, i64* %328
  %329 = load i64, i64* %316
  %330 = alloca i64*
  %331 = alloca %ListMaker*
  %loadvar34 = load %ListMaker*, %ListMaker** %m
  %332 = ptrtoint %ListMaker** %331 to i64
  %333 = add i64 %332, 0
  %334 = inttoptr i64 %333 to %ListMaker**
  store %ListMaker* %loadvar34, %ListMaker** %334
  %335 = load %ListMaker*, %ListMaker** %331
  %336 = alloca i64
  %loadvar35 = load i64, i64* %9
  %337 = ptrtoint i64* %336 to i64
  %338 = add i64 %337, 0
  %339 = inttoptr i64 %338 to i64*
  store i64 %loadvar35, i64* %339
  %340 = load i64, i64* %336
  %341 = alloca i64*
  %loadvar36 = load i64*, i64** %10
  %342 = ptrtoint i64** %341 to i64
  %343 = add i64 %342, 0
  %344 = inttoptr i64 %343 to i64**
  store i64* %loadvar36, i64** %344
  %345 = load i64*, i64** %341
  %346 = ptrtoint %ListMaker* %335 to i64
  %347 = add i64 %346, 0
  %348 = inttoptr i64 %347 to %ListMaker*
  %349 = getelementptr inbounds %ListMaker, %ListMaker* %348, i32 0, i32 1
  %350 = load %ListMaker_vtable*, %ListMaker_vtable** %349
  %351 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %350, i32 0, i32 2
  %352 = load i64* (%ListMaker*, i64, i64*)*, i64* (%ListMaker*, i64, i64*)** %351
  %353 = call i64* %352(%ListMaker* %335, i64 %340, i64* %345)
  %354 = ptrtoint i64** %330 to i64
  %355 = add i64 %354, 0
  %356 = inttoptr i64 %355 to i64**
  store i64* %353, i64** %356
  %357 = load i64*, i64** %330
  %358 = alloca i64*
  %loadvar37 = load i64*, i64** %11
  %359 = ptrtoint i64** %358 to i64
  %360 = add i64 %359, 0
  %361 = inttoptr i64 %360 to i64**
  store i64* %loadvar37, i64** %361
  %362 = load i64*, i64** %358
  %363 = ptrtoint %Runner* %287 to i64
  %364 = add i64 %363, 0
  %365 = inttoptr i64 %364 to %Runner*
  %366 = getelementptr inbounds %Runner, %Runner* %365, i32 0, i32 1
  %367 = load %Runner_vtable*, %Runner_vtable** %366
  %368 = getelementptr inbounds %Runner_vtable, %Runner_vtable* %367, i32 0, i32 1
  %369 = load i64 (%Runner*, i64*, i64*, i64, i64*, i64*)*, i64 (%Runner*, i64*, i64*, i64, i64*, i64*)** %368
  %370 = call i64 %369(%Runner* %287, i64* %301, i64* %315, i64 %329, i64* %357, i64* %362)
  %371 = ptrtoint i64* %c to i64
  %372 = add i64 %371, 0
  %373 = inttoptr i64 %372 to i64*
  store i64 %370, i64* %373
  br label %ifcont.39

else.38:                                          ; preds = %ifcont.29
  %374 = ptrtoint i64* %c to i64
  %375 = add i64 %374, 0
  %376 = inttoptr i64 %375 to i64*
  store i64 0, i64* %376
  br label %ifcont.39

ifcont.39:                                        ; preds = %else.38, %then32
  %377 = load i64*, i64** %7
  %378 = ptrtoint i64* %377 to i64
  %379 = add i64 %378, 8
  %380 = inttoptr i64 %379 to i64*
  store i64 0, i64* %380
  %381 = ptrtoint i64* %377 to i64
  %382 = add i64 %381, 0
  %383 = inttoptr i64 %382 to i64 (i64*)**
  %384 = load i64 (i64*)*, i64 (i64*)** %383
  %385 = call i64 %384(i64* %377)
  %ultcmptmp40 = icmp eq i64 %385, 43
  %ifcond41 = icmp ne i1 %ultcmptmp40, false
  br i1 %ifcond41, label %then42, label %else.48

then42:                                           ; preds = %ifcont.39
  %386 = alloca %Runner*
  %loadvar43 = load %Runner*, %Runner** %r
  %387 = ptrtoint %Runner** %386 to i64
  %388 = add i64 %387, 0
  %389 = inttoptr i64 %388 to %Runner**
  store %Runner* %loadvar43, %Runner** %389
  %390 = load %Runner*, %Runner** %386
  %391 = alloca i64*
  %392 = load i64*, i64** %7
  %393 = ptrtoint i64* %392 to i64
  %394 = add i64 %393, 8
  %395 = inttoptr i64 %394 to i64*
  store i64 1, i64* %395
  %396 = ptrtoint i64* %392 to i64
  %397 = add i64 %396, 0
  %398 = inttoptr i64 %397 to i64 (i64*)**
  %399 = load i64 (i64*)*, i64 (i64*)** %398
  %400 = call i64 %399(i64* %392)
  %401 = ptrtoint i64** %391 to i64
  %402 = add i64 %401, 0
  %403 = inttoptr i64 %402 to i64*
  store i64 %400, i64* %403
  %404 = load i64*, i64** %391
  %405 = alloca i64*
  %loadvar44 = load i64*, i64** %8
  %406 = ptrtoint i64** %405 to i64
  %407 = add i64 %406, 0
  %408 = inttoptr i64 %407 to i64**
  store i64* %loadvar44, i64** %408
  %409 = load i64*, i64** %405
  %410 = alloca i64
  %loadvar45 = load i64, i64* %9
  %addtmp = add i64 %loadvar45, 1
  %411 = ptrtoint i64* %410 to i64
  %412 = add i64 %411, 0
  %413 = inttoptr i64 %412 to i64*
  store i64 %addtmp, i64* %413
  %414 = load i64, i64* %410
  %415 = alloca i64*
  %loadvar46 = load i64*, i64** %10
  %416 = ptrtoint i64** %415 to i64
  %417 = add i64 %416, 0
  %418 = inttoptr i64 %417 to i64**
  store i64* %loadvar46, i64** %418
  %419 = load i64*, i64** %415
  %420 = alloca i64*
  %loadvar47 = load i64*, i64** %11
  %421 = ptrtoint i64** %420 to i64
  %422 = add i64 %421, 0
  %423 = inttoptr i64 %422 to i64**
  store i64* %loadvar47, i64** %423
  %424 = load i64*, i64** %420
  %425 = ptrtoint %Runner* %390 to i64
  %426 = add i64 %425, 0
  %427 = inttoptr i64 %426 to %Runner*
  %428 = getelementptr inbounds %Runner, %Runner* %427, i32 0, i32 1
  %429 = load %Runner_vtable*, %Runner_vtable** %428
  %430 = getelementptr inbounds %Runner_vtable, %Runner_vtable* %429, i32 0, i32 1
  %431 = load i64 (%Runner*, i64*, i64*, i64, i64*, i64*)*, i64 (%Runner*, i64*, i64*, i64, i64*, i64*)** %430
  %432 = call i64 %431(%Runner* %390, i64* %404, i64* %409, i64 %414, i64* %419, i64* %424)
  %433 = ptrtoint i64* %c to i64
  %434 = add i64 %433, 0
  %435 = inttoptr i64 %434 to i64*
  store i64 %432, i64* %435
  br label %ifcont.49

else.48:                                          ; preds = %ifcont.39
  %436 = ptrtoint i64* %c to i64
  %437 = add i64 %436, 0
  %438 = inttoptr i64 %437 to i64*
  store i64 0, i64* %438
  br label %ifcont.49

ifcont.49:                                        ; preds = %else.48, %then42
  %439 = load i64*, i64** %7
  %440 = ptrtoint i64* %439 to i64
  %441 = add i64 %440, 8
  %442 = inttoptr i64 %441 to i64*
  store i64 0, i64* %442
  %443 = ptrtoint i64* %439 to i64
  %444 = add i64 %443, 0
  %445 = inttoptr i64 %444 to i64 (i64*)**
  %446 = load i64 (i64*)*, i64 (i64*)** %445
  %447 = call i64 %446(i64* %439)
  %ultcmptmp50 = icmp eq i64 %447, 45
  %ifcond51 = icmp ne i1 %ultcmptmp50, false
  br i1 %ifcond51, label %then52, label %else.59

then52:                                           ; preds = %ifcont.49
  %448 = alloca %Runner*
  %loadvar53 = load %Runner*, %Runner** %r
  %449 = ptrtoint %Runner** %448 to i64
  %450 = add i64 %449, 0
  %451 = inttoptr i64 %450 to %Runner**
  store %Runner* %loadvar53, %Runner** %451
  %452 = load %Runner*, %Runner** %448
  %453 = alloca i64*
  %454 = load i64*, i64** %7
  %455 = ptrtoint i64* %454 to i64
  %456 = add i64 %455, 8
  %457 = inttoptr i64 %456 to i64*
  store i64 1, i64* %457
  %458 = ptrtoint i64* %454 to i64
  %459 = add i64 %458, 0
  %460 = inttoptr i64 %459 to i64 (i64*)**
  %461 = load i64 (i64*)*, i64 (i64*)** %460
  %462 = call i64 %461(i64* %454)
  %463 = ptrtoint i64** %453 to i64
  %464 = add i64 %463, 0
  %465 = inttoptr i64 %464 to i64*
  store i64 %462, i64* %465
  %466 = load i64*, i64** %453
  %467 = alloca i64*
  %loadvar54 = load i64*, i64** %8
  %468 = ptrtoint i64** %467 to i64
  %469 = add i64 %468, 0
  %470 = inttoptr i64 %469 to i64**
  store i64* %loadvar54, i64** %470
  %471 = load i64*, i64** %467
  %472 = alloca i64
  %loadvar55 = load i64, i64* %9
  %addtmp56 = sub i64 %loadvar55, 1
  %473 = ptrtoint i64* %472 to i64
  %474 = add i64 %473, 0
  %475 = inttoptr i64 %474 to i64*
  store i64 %addtmp56, i64* %475
  %476 = load i64, i64* %472
  %477 = alloca i64*
  %loadvar57 = load i64*, i64** %10
  %478 = ptrtoint i64** %477 to i64
  %479 = add i64 %478, 0
  %480 = inttoptr i64 %479 to i64**
  store i64* %loadvar57, i64** %480
  %481 = load i64*, i64** %477
  %482 = alloca i64*
  %loadvar58 = load i64*, i64** %11
  %483 = ptrtoint i64** %482 to i64
  %484 = add i64 %483, 0
  %485 = inttoptr i64 %484 to i64**
  store i64* %loadvar58, i64** %485
  %486 = load i64*, i64** %482
  %487 = ptrtoint %Runner* %452 to i64
  %488 = add i64 %487, 0
  %489 = inttoptr i64 %488 to %Runner*
  %490 = getelementptr inbounds %Runner, %Runner* %489, i32 0, i32 1
  %491 = load %Runner_vtable*, %Runner_vtable** %490
  %492 = getelementptr inbounds %Runner_vtable, %Runner_vtable* %491, i32 0, i32 1
  %493 = load i64 (%Runner*, i64*, i64*, i64, i64*, i64*)*, i64 (%Runner*, i64*, i64*, i64, i64*, i64*)** %492
  %494 = call i64 %493(%Runner* %452, i64* %466, i64* %471, i64 %476, i64* %481, i64* %486)
  %495 = ptrtoint i64* %c to i64
  %496 = add i64 %495, 0
  %497 = inttoptr i64 %496 to i64*
  store i64 %494, i64* %497
  br label %ifcont.60

else.59:                                          ; preds = %ifcont.49
  %498 = ptrtoint i64* %c to i64
  %499 = add i64 %498, 0
  %500 = inttoptr i64 %499 to i64*
  store i64 0, i64* %500
  br label %ifcont.60

ifcont.60:                                        ; preds = %else.59, %then52
  %501 = load i64*, i64** %7
  %502 = ptrtoint i64* %501 to i64
  %503 = add i64 %502, 8
  %504 = inttoptr i64 %503 to i64*
  store i64 0, i64* %504
  %505 = ptrtoint i64* %501 to i64
  %506 = add i64 %505, 0
  %507 = inttoptr i64 %506 to i64 (i64*)**
  %508 = load i64 (i64*)*, i64 (i64*)** %507
  %509 = call i64 %508(i64* %501)
  %ultcmptmp61 = icmp eq i64 %509, 44
  %ifcond62 = icmp ne i1 %ultcmptmp61, false
  br i1 %ifcond62, label %then63, label %else.68

then63:                                           ; preds = %ifcont.60
  %510 = alloca %Runner*
  %loadvar64 = load %Runner*, %Runner** %r
  %511 = ptrtoint %Runner** %510 to i64
  %512 = add i64 %511, 0
  %513 = inttoptr i64 %512 to %Runner**
  store %Runner* %loadvar64, %Runner** %513
  %514 = load %Runner*, %Runner** %510
  %515 = alloca i64*
  %516 = load i64*, i64** %7
  %517 = ptrtoint i64* %516 to i64
  %518 = add i64 %517, 8
  %519 = inttoptr i64 %518 to i64*
  store i64 1, i64* %519
  %520 = ptrtoint i64* %516 to i64
  %521 = add i64 %520, 0
  %522 = inttoptr i64 %521 to i64 (i64*)**
  %523 = load i64 (i64*)*, i64 (i64*)** %522
  %524 = call i64 %523(i64* %516)
  %525 = ptrtoint i64** %515 to i64
  %526 = add i64 %525, 0
  %527 = inttoptr i64 %526 to i64*
  store i64 %524, i64* %527
  %528 = load i64*, i64** %515
  %529 = alloca i64*
  %loadvar65 = load i64*, i64** %8
  %530 = ptrtoint i64** %529 to i64
  %531 = add i64 %530, 0
  %532 = inttoptr i64 %531 to i64**
  store i64* %loadvar65, i64** %532
  %533 = load i64*, i64** %529
  %534 = alloca i64
  %535 = alloca i64
  store i64 0, i64* %535
  %536 = call i64 @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @2, i32 0, i32 0), i64* %535)
  %537 = load i64, i64* %535
  %538 = ptrtoint i64* %534 to i64
  %539 = add i64 %538, 0
  %540 = inttoptr i64 %539 to i64*
  store i64 %537, i64* %540
  %541 = load i64, i64* %534
  %542 = alloca i64*
  %loadvar66 = load i64*, i64** %10
  %543 = ptrtoint i64** %542 to i64
  %544 = add i64 %543, 0
  %545 = inttoptr i64 %544 to i64**
  store i64* %loadvar66, i64** %545
  %546 = load i64*, i64** %542
  %547 = alloca i64*
  %loadvar67 = load i64*, i64** %11
  %548 = ptrtoint i64** %547 to i64
  %549 = add i64 %548, 0
  %550 = inttoptr i64 %549 to i64**
  store i64* %loadvar67, i64** %550
  %551 = load i64*, i64** %547
  %552 = ptrtoint %Runner* %514 to i64
  %553 = add i64 %552, 0
  %554 = inttoptr i64 %553 to %Runner*
  %555 = getelementptr inbounds %Runner, %Runner* %554, i32 0, i32 1
  %556 = load %Runner_vtable*, %Runner_vtable** %555
  %557 = getelementptr inbounds %Runner_vtable, %Runner_vtable* %556, i32 0, i32 1
  %558 = load i64 (%Runner*, i64*, i64*, i64, i64*, i64*)*, i64 (%Runner*, i64*, i64*, i64, i64*, i64*)** %557
  %559 = call i64 %558(%Runner* %514, i64* %528, i64* %533, i64 %541, i64* %546, i64* %551)
  %560 = ptrtoint i64* %c to i64
  %561 = add i64 %560, 0
  %562 = inttoptr i64 %561 to i64*
  store i64 %559, i64* %562
  br label %ifcont.69

else.68:                                          ; preds = %ifcont.60
  %563 = ptrtoint i64* %c to i64
  %564 = add i64 %563, 0
  %565 = inttoptr i64 %564 to i64*
  store i64 0, i64* %565
  br label %ifcont.69

ifcont.69:                                        ; preds = %else.68, %then63
  %566 = load i64*, i64** %7
  %567 = ptrtoint i64* %566 to i64
  %568 = add i64 %567, 8
  %569 = inttoptr i64 %568 to i64*
  store i64 0, i64* %569
  %570 = ptrtoint i64* %566 to i64
  %571 = add i64 %570, 0
  %572 = inttoptr i64 %571 to i64 (i64*)**
  %573 = load i64 (i64*)*, i64 (i64*)** %572
  %574 = call i64 %573(i64* %566)
  %ultcmptmp70 = icmp eq i64 %574, 46
  %ifcond71 = icmp ne i1 %ultcmptmp70, false
  br i1 %ifcond71, label %then72, label %else.79

then72:                                           ; preds = %ifcont.69
  %loadvar73 = load i64, i64* %9
  %575 = call i64 @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @3, i32 0, i32 0), i64 %loadvar73)
  %576 = alloca %Runner*
  %loadvar74 = load %Runner*, %Runner** %r
  %577 = ptrtoint %Runner** %576 to i64
  %578 = add i64 %577, 0
  %579 = inttoptr i64 %578 to %Runner**
  store %Runner* %loadvar74, %Runner** %579
  %580 = load %Runner*, %Runner** %576
  %581 = alloca i64*
  %582 = load i64*, i64** %7
  %583 = ptrtoint i64* %582 to i64
  %584 = add i64 %583, 8
  %585 = inttoptr i64 %584 to i64*
  store i64 1, i64* %585
  %586 = ptrtoint i64* %582 to i64
  %587 = add i64 %586, 0
  %588 = inttoptr i64 %587 to i64 (i64*)**
  %589 = load i64 (i64*)*, i64 (i64*)** %588
  %590 = call i64 %589(i64* %582)
  %591 = ptrtoint i64** %581 to i64
  %592 = add i64 %591, 0
  %593 = inttoptr i64 %592 to i64*
  store i64 %590, i64* %593
  %594 = load i64*, i64** %581
  %595 = alloca i64*
  %loadvar75 = load i64*, i64** %8
  %596 = ptrtoint i64** %595 to i64
  %597 = add i64 %596, 0
  %598 = inttoptr i64 %597 to i64**
  store i64* %loadvar75, i64** %598
  %599 = load i64*, i64** %595
  %600 = alloca i64
  %loadvar76 = load i64, i64* %9
  %601 = ptrtoint i64* %600 to i64
  %602 = add i64 %601, 0
  %603 = inttoptr i64 %602 to i64*
  store i64 %loadvar76, i64* %603
  %604 = load i64, i64* %600
  %605 = alloca i64*
  %loadvar77 = load i64*, i64** %10
  %606 = ptrtoint i64** %605 to i64
  %607 = add i64 %606, 0
  %608 = inttoptr i64 %607 to i64**
  store i64* %loadvar77, i64** %608
  %609 = load i64*, i64** %605
  %610 = alloca i64*
  %loadvar78 = load i64*, i64** %11
  %611 = ptrtoint i64** %610 to i64
  %612 = add i64 %611, 0
  %613 = inttoptr i64 %612 to i64**
  store i64* %loadvar78, i64** %613
  %614 = load i64*, i64** %610
  %615 = ptrtoint %Runner* %580 to i64
  %616 = add i64 %615, 0
  %617 = inttoptr i64 %616 to %Runner*
  %618 = getelementptr inbounds %Runner, %Runner* %617, i32 0, i32 1
  %619 = load %Runner_vtable*, %Runner_vtable** %618
  %620 = getelementptr inbounds %Runner_vtable, %Runner_vtable* %619, i32 0, i32 1
  %621 = load i64 (%Runner*, i64*, i64*, i64, i64*, i64*)*, i64 (%Runner*, i64*, i64*, i64, i64*, i64*)** %620
  %622 = call i64 %621(%Runner* %580, i64* %594, i64* %599, i64 %604, i64* %609, i64* %614)
  %623 = ptrtoint i64* %c to i64
  %624 = add i64 %623, 0
  %625 = inttoptr i64 %624 to i64*
  store i64 %622, i64* %625
  br label %ifcont.80

else.79:                                          ; preds = %ifcont.69
  %626 = ptrtoint i64* %c to i64
  %627 = add i64 %626, 0
  %628 = inttoptr i64 %627 to i64*
  store i64 0, i64* %628
  br label %ifcont.80

ifcont.80:                                        ; preds = %else.79, %then72
  %629 = load i64*, i64** %7
  %630 = ptrtoint i64* %629 to i64
  %631 = add i64 %630, 8
  %632 = inttoptr i64 %631 to i64*
  store i64 0, i64* %632
  %633 = ptrtoint i64* %629 to i64
  %634 = add i64 %633, 0
  %635 = inttoptr i64 %634 to i64 (i64*)**
  %636 = load i64 (i64*)*, i64 (i64*)** %635
  %637 = call i64 %636(i64* %629)
  %ultcmptmp81 = icmp eq i64 %637, 91
  %ifcond82 = icmp ne i1 %ultcmptmp81, false
  br i1 %ifcond82, label %then83, label %else.91

then83:                                           ; preds = %ifcont.80
  %638 = alloca %Runner*
  %loadvar84 = load %Runner*, %Runner** %r
  %639 = ptrtoint %Runner** %638 to i64
  %640 = add i64 %639, 0
  %641 = inttoptr i64 %640 to %Runner**
  store %Runner* %loadvar84, %Runner** %641
  %642 = load %Runner*, %Runner** %638
  %643 = alloca i64*
  %644 = load i64*, i64** %7
  %645 = ptrtoint i64* %644 to i64
  %646 = add i64 %645, 8
  %647 = inttoptr i64 %646 to i64*
  store i64 1, i64* %647
  %648 = ptrtoint i64* %644 to i64
  %649 = add i64 %648, 0
  %650 = inttoptr i64 %649 to i64 (i64*)**
  %651 = load i64 (i64*)*, i64 (i64*)** %650
  %652 = call i64 %651(i64* %644)
  %653 = ptrtoint i64** %643 to i64
  %654 = add i64 %653, 0
  %655 = inttoptr i64 %654 to i64*
  store i64 %652, i64* %655
  %656 = load i64*, i64** %643
  %657 = alloca i64*
  %loadvar85 = load i64*, i64** %8
  %658 = ptrtoint i64** %657 to i64
  %659 = add i64 %658, 0
  %660 = inttoptr i64 %659 to i64**
  store i64* %loadvar85, i64** %660
  %661 = load i64*, i64** %657
  %662 = alloca i64
  %loadvar86 = load i64, i64* %9
  %663 = ptrtoint i64* %662 to i64
  %664 = add i64 %663, 0
  %665 = inttoptr i64 %664 to i64*
  store i64 %loadvar86, i64* %665
  %666 = load i64, i64* %662
  %667 = alloca i64*
  %loadvar87 = load i64*, i64** %10
  %668 = ptrtoint i64** %667 to i64
  %669 = add i64 %668, 0
  %670 = inttoptr i64 %669 to i64**
  store i64* %loadvar87, i64** %670
  %671 = load i64*, i64** %667
  %672 = alloca i64*
  %673 = alloca %ListMaker*
  %loadvar88 = load %ListMaker*, %ListMaker** %m
  %674 = ptrtoint %ListMaker** %673 to i64
  %675 = add i64 %674, 0
  %676 = inttoptr i64 %675 to %ListMaker**
  store %ListMaker* %loadvar88, %ListMaker** %676
  %677 = load %ListMaker*, %ListMaker** %673
  %678 = alloca i64
  %loadvar89 = load i64*, i64** %7
  %679 = ptrtoint i64* %678 to i64
  %680 = add i64 %679, 0
  %681 = inttoptr i64 %680 to i64**
  store i64* %loadvar89, i64** %681
  %682 = load i64, i64* %678
  %683 = alloca i64*
  %loadvar90 = load i64*, i64** %11
  %684 = ptrtoint i64** %683 to i64
  %685 = add i64 %684, 0
  %686 = inttoptr i64 %685 to i64**
  store i64* %loadvar90, i64** %686
  %687 = load i64*, i64** %683
  %688 = ptrtoint %ListMaker* %677 to i64
  %689 = add i64 %688, 0
  %690 = inttoptr i64 %689 to %ListMaker*
  %691 = getelementptr inbounds %ListMaker, %ListMaker* %690, i32 0, i32 1
  %692 = load %ListMaker_vtable*, %ListMaker_vtable** %691
  %693 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %692, i32 0, i32 2
  %694 = load i64* (%ListMaker*, i64, i64*)*, i64* (%ListMaker*, i64, i64*)** %693
  %695 = call i64* %694(%ListMaker* %677, i64 %682, i64* %687)
  %696 = ptrtoint i64** %672 to i64
  %697 = add i64 %696, 0
  %698 = inttoptr i64 %697 to i64**
  store i64* %695, i64** %698
  %699 = load i64*, i64** %672
  %700 = ptrtoint %Runner* %642 to i64
  %701 = add i64 %700, 0
  %702 = inttoptr i64 %701 to %Runner*
  %703 = getelementptr inbounds %Runner, %Runner* %702, i32 0, i32 1
  %704 = load %Runner_vtable*, %Runner_vtable** %703
  %705 = getelementptr inbounds %Runner_vtable, %Runner_vtable* %704, i32 0, i32 1
  %706 = load i64 (%Runner*, i64*, i64*, i64, i64*, i64*)*, i64 (%Runner*, i64*, i64*, i64, i64*, i64*)** %705
  %707 = call i64 %706(%Runner* %642, i64* %656, i64* %661, i64 %666, i64* %671, i64* %699)
  %708 = ptrtoint i64* %c to i64
  %709 = add i64 %708, 0
  %710 = inttoptr i64 %709 to i64*
  store i64 %707, i64* %710
  br label %ifcont.92

else.91:                                          ; preds = %ifcont.80
  %711 = ptrtoint i64* %c to i64
  %712 = add i64 %711, 0
  %713 = inttoptr i64 %712 to i64*
  store i64 0, i64* %713
  br label %ifcont.92

ifcont.92:                                        ; preds = %else.91, %then83
  %loadvar93 = load i64, i64* %c
  ret i64 %loadvar93
}

declare i64 @scanf(i8*, i64*)

declare i64 @printf(i8*, i64)

define i32 @main() {
entry:
  %Brainfuck = alloca %Runner*
  %m = alloca %ListMaker*
  %malloccall = tail call i8* @malloc(i64 ptrtoint (%ListMaker* getelementptr (%ListMaker, %ListMaker* null, i32 1) to i64))
  %0 = bitcast i8* %malloccall to %ListMaker*
  %1 = getelementptr inbounds %ListMaker, %ListMaker* %0, i32 0, i32 1
  store %ListMaker_vtable* @ListMaker_vatble_loc, %ListMaker_vtable** %1
  %2 = getelementptr inbounds %ListMaker, %ListMaker* %0, i32 0, i32 0
  store i64 1, i64* %2
  %3 = ptrtoint %ListMaker** %m to i64
  %4 = add i64 %3, 0
  %5 = inttoptr i64 %4 to %ListMaker**
  store %ListMaker* %0, %ListMaker** %5
  %malloccall.1 = tail call i8* @malloc(i64 ptrtoint (%Runner* getelementptr (%Runner, %Runner* null, i32 1) to i64))
  %6 = bitcast i8* %malloccall.1 to %Runner*
  %7 = getelementptr inbounds %Runner, %Runner* %6, i32 0, i32 1
  store %Runner_vtable* @Runner_vatble_loc, %Runner_vtable** %7
  %8 = getelementptr inbounds %Runner, %Runner* %6, i32 0, i32 0
  store i64 2, i64* %8
  %9 = ptrtoint %Runner** %Brainfuck to i64
  %10 = add i64 %9, 0
  %11 = inttoptr i64 %10 to %Runner**
  store %Runner* %6, %Runner** %11
  %c = alloca i64
  %12 = alloca %Runner*
  %loadvar = load %Runner*, %Runner** %Brainfuck
  %13 = ptrtoint %Runner** %12 to i64
  %14 = add i64 %13, 0
  %15 = inttoptr i64 %14 to %Runner**
  store %Runner* %loadvar, %Runner** %15
  %16 = load %Runner*, %Runner** %12
  %17 = alloca i64*
  %18 = alloca %Runner*
  %loadvar2 = load %Runner*, %Runner** %Brainfuck
  %19 = ptrtoint %Runner** %18 to i64
  %20 = add i64 %19, 0
  %21 = inttoptr i64 %20 to %Runner**
  store %Runner* %loadvar2, %Runner** %21
  %22 = load %Runner*, %Runner** %18
  %23 = ptrtoint %Runner* %22 to i64
  %24 = add i64 %23, 0
  %25 = inttoptr i64 %24 to %Runner*
  %26 = getelementptr inbounds %Runner, %Runner* %25, i32 0, i32 1
  %27 = load %Runner_vtable*, %Runner_vtable** %26
  %28 = getelementptr inbounds %Runner_vtable, %Runner_vtable* %27, i32 0, i32 0
  %29 = load i64* (%Runner*)*, i64* (%Runner*)** %28
  %30 = call i64* %29(%Runner* %22)
  %31 = ptrtoint i64** %17 to i64
  %32 = add i64 %31, 0
  %33 = inttoptr i64 %32 to i64**
  store i64* %30, i64** %33
  %34 = load i64*, i64** %17
  %35 = alloca i64*
  %36 = alloca %ListMaker*
  %loadvar3 = load %ListMaker*, %ListMaker** %m
  %37 = ptrtoint %ListMaker** %36 to i64
  %38 = add i64 %37, 0
  %39 = inttoptr i64 %38 to %ListMaker**
  store %ListMaker* %loadvar3, %ListMaker** %39
  %40 = load %ListMaker*, %ListMaker** %36
  %41 = ptrtoint %ListMaker* %40 to i64
  %42 = add i64 %41, 0
  %43 = inttoptr i64 %42 to %ListMaker*
  %44 = getelementptr inbounds %ListMaker, %ListMaker* %43, i32 0, i32 1
  %45 = load %ListMaker_vtable*, %ListMaker_vtable** %44
  %46 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %45, i32 0, i32 0
  %47 = load i64* (%ListMaker*)*, i64* (%ListMaker*)** %46
  %48 = call i64* %47(%ListMaker* %40)
  %49 = ptrtoint i64** %35 to i64
  %50 = add i64 %49, 0
  %51 = inttoptr i64 %50 to i64**
  store i64* %48, i64** %51
  %52 = load i64*, i64** %35
  %53 = alloca i64
  %54 = ptrtoint i64* %53 to i64
  %55 = add i64 %54, 0
  %56 = inttoptr i64 %55 to i64*
  store i64 0, i64* %56
  %57 = load i64, i64* %53
  %58 = alloca i64*
  %59 = alloca %ListMaker*
  %loadvar4 = load %ListMaker*, %ListMaker** %m
  %60 = ptrtoint %ListMaker** %59 to i64
  %61 = add i64 %60, 0
  %62 = inttoptr i64 %61 to %ListMaker**
  store %ListMaker* %loadvar4, %ListMaker** %62
  %63 = load %ListMaker*, %ListMaker** %59
  %64 = ptrtoint %ListMaker* %63 to i64
  %65 = add i64 %64, 0
  %66 = inttoptr i64 %65 to %ListMaker*
  %67 = getelementptr inbounds %ListMaker, %ListMaker* %66, i32 0, i32 1
  %68 = load %ListMaker_vtable*, %ListMaker_vtable** %67
  %69 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %68, i32 0, i32 0
  %70 = load i64* (%ListMaker*)*, i64* (%ListMaker*)** %69
  %71 = call i64* %70(%ListMaker* %63)
  %72 = ptrtoint i64** %58 to i64
  %73 = add i64 %72, 0
  %74 = inttoptr i64 %73 to i64**
  store i64* %71, i64** %74
  %75 = load i64*, i64** %58
  %76 = alloca i64*
  %77 = alloca %ListMaker*
  %loadvar5 = load %ListMaker*, %ListMaker** %m
  %78 = ptrtoint %ListMaker** %77 to i64
  %79 = add i64 %78, 0
  %80 = inttoptr i64 %79 to %ListMaker**
  store %ListMaker* %loadvar5, %ListMaker** %80
  %81 = load %ListMaker*, %ListMaker** %77
  %82 = ptrtoint %ListMaker* %81 to i64
  %83 = add i64 %82, 0
  %84 = inttoptr i64 %83 to %ListMaker*
  %85 = getelementptr inbounds %ListMaker, %ListMaker* %84, i32 0, i32 1
  %86 = load %ListMaker_vtable*, %ListMaker_vtable** %85
  %87 = getelementptr inbounds %ListMaker_vtable, %ListMaker_vtable* %86, i32 0, i32 0
  %88 = load i64* (%ListMaker*)*, i64* (%ListMaker*)** %87
  %89 = call i64* %88(%ListMaker* %81)
  %90 = ptrtoint i64** %76 to i64
  %91 = add i64 %90, 0
  %92 = inttoptr i64 %91 to i64**
  store i64* %89, i64** %92
  %93 = load i64*, i64** %76
  %94 = ptrtoint %Runner* %16 to i64
  %95 = add i64 %94, 0
  %96 = inttoptr i64 %95 to %Runner*
  %97 = getelementptr inbounds %Runner, %Runner* %96, i32 0, i32 1
  %98 = load %Runner_vtable*, %Runner_vtable** %97
  %99 = getelementptr inbounds %Runner_vtable, %Runner_vtable* %98, i32 0, i32 1
  %100 = load i64 (%Runner*, i64*, i64*, i64, i64*, i64*)*, i64 (%Runner*, i64*, i64*, i64, i64*, i64*)** %99
  %101 = call i64 %100(%Runner* %16, i64* %34, i64* %52, i64 %57, i64* %75, i64* %93)
  %102 = ptrtoint i64* %c to i64
  %103 = add i64 %102, 0
  %104 = inttoptr i64 %103 to i64*
  store i64 %101, i64* %104
  ret i32 0
}
