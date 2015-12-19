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
	A x=new A();
	System.out.println(A.getCnt());
	System.out.println(A.getCnt());
	System.out.println(A.getCnt());
	System.out.println(A.getCnt());
    }
}
