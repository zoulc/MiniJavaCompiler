class A{
	
	int Cnt;

	public int  getCnt()
	{
		Cnt=Cnt+1;
		return Cnt;
	}
}

class Test{
    public static void main(String[] a){
	int a ;
	a = System.in.read(); 
	while (  a <5  ) { 
		a = a + 1 ; 
	}
	System.out.println(a);
    }
}
