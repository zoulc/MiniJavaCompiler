class Test{
    public static void main(String[] a){
	int a ;
	a = 1 ; 
	while (  a <10  ) { 
		a = a + 1 ; 
	}
	Tester b ; 
        b = new Tester();
	a = b.work();
	System.out.println(new QS().Start(10));
    }
}

class Tester{
    int a ; 
    public int work() {
         return a + 1 ; 
    }
}

class Tseter2 extends Tester {
    int b ; 
    public int work() {
	return b + 1 ; 
    }
}
