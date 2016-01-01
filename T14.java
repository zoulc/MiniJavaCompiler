class Test{
	public static void main(String[] a){
		Runner Brainfuck;
		ListMaker m;
		m=new ListMaker();
		Brainfuck=new Runner();
		int c;
		c=Brainfuck.run_program(Brainfuck.load_program(),m.null_list(),0,m.null_list(),m.null_list());
	}
}

class ListMaker{


	public Invoker null_list()
	{
		ListMaker m;
		m=new ListMaker();	
		return (int n)->{
			int c;
			if(1<n)c=1;
			else
			{
				if(n<1)c=0;
					else c=m.null_list();
			}
			return c;
		};
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
		{
			if(n<1)ans=x;
				else ans=m.after(x(1),n-1);
		}
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


class Runner
{
	public Invoker load_program()
	{
			ListMaker m;
			m=new ListMaker();
			Invoker c;
			int a;
			c=m.null_list();
			a=System.in.getc();
			while(a!=10)
			{
				c=m.insert_at_tail(c,a);
				a=System.in.getc();
			}
			return c;
	}
	
	public int run_program(Invoker program,Invoker pre,int ptr,Invoker suc,Invoker preprogram)
	{
			int c;
			ListMaker m;
			m=new ListMaker();
			Runner r;
			r=new Runner();
			if(program(2)==1)
				c=0;
			else c=0;
			if(program(0)==93)
			{
				if(ptr==0)c=r.run_program(program(1),pre,ptr,suc,preprogram(1));
					else c=r.run_program(preprogram(0),pre,ptr,suc,preprogram(1));
			}
			else c=0;
			if(program(0)==62)
				c=r.run_program(program(1),m.link(ptr,pre),suc(0),suc(1),preprogram);
			else c=0;
			if(program(0)==60)
				c=r.run_program(program(1),pre(1),pre(0),m.link(ptr,suc),preprogram);
			else c=0;
			if(program(0)==43)
				c=r.run_program(program(1),pre,ptr+1,suc,preprogram);
			else c=0;
			if(program(0)==45)
				c=r.run_program(program(1),pre,ptr-1,suc,preprogram);
			else c=0;
			if(program(0)==44)
				c=r.run_program(program(1),pre,System.in.getc(),suc,preprogram);
			else c=0;
			if(program(0)==46)
			{
				System.out.putc(ptr);
				c=r.run_program(program(1),pre,ptr,suc,preprogram);
			}
			else c=0;
			if(program(0)==91)
				c=r.run_program(program(1),pre,ptr,suc,m.link(program,preprogram));
			else c=0;
			return c;
	}
}

