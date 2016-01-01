class Test{
	public static void main(String[] a){
		ListMaker m;
		m=new ListMaker();
		Invoker L;
		int c;
		L=m.null_list();
		L=m.insert_at_head(L,5);			
		L=m.insert_at_head(L,4);			
		L=m.insert_at_head(L,3);			
		L=m.insert_at_head(L,2);			
		L=m.insert_at_head(L,1);			
		c=m.get_len(L);
		System.out.println(c);			
		c=m.at(L,1);
		System.out.println(c);			
	}
}

class ListMaker{


	public Invoker null_list()
	{
		return (int n)->{return 1;};
	}
	
	public int is_null_list(Invoker x)
	{
		return x(2);
	}

	public Invoker link(int x,Invoker y)
	{
		return (int n)->{
			int c;
			if(1<n)c=0;
			else
			{
				if(n<1)c=x;
					else c=y;
			}
			return c;
		};
	}

	public Invoker insert_at_tail(Invoker x,int y)
	{
		ListMaker m;
		m=new ListMaker();
		Invoker z;
		if(0<m.is_null_list(x))
			z=m.link(y,x);
		else
			z=m.link(x(0),m.insert_at_tail(x(1),y));
		return z;
	}

	public int get_len(Invoker x)
	{
		ListMaker m;
		m=new ListMaker();
		int c;
		if(0<m.is_null_list(x))c=0;
		else c=m.get_len(x(1))+1;
		return c;
	}
	
	public Invoker insert_at_head(Invoker x,int y)
	{
		ListMaker m;
		m=new ListMaker();
		Invoker z;
		z=m.link(y,x);
		return z;
	}

	public Invoker after(Invoker x,int n)
	{
		ListMaker m;
		m=new ListMaker();
		Invoker ans;
		if(0<m.is_null_list(x))
			ans=x;
		else
//		{
			if(n<1)ans=x;
				else ans=m.after(x(1),n-1);
//		}
		return ans;
	}

	public int at(Invoker x,int n)
	{
		ListMaker m;
		m=new ListMaker();
		Invoker afterx;
		afterx=m.after(x,n);
		return afterx(0);
	}

}
