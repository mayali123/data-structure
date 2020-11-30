#include"string.cpp"
Str Maxsub(Str st)
{
	Str maxsub_st;
	maxsub_st.length = 0;
	int i,j,index=0,len=0,max_len=0;
	for(i=0;i<st.length;i++)
	{
		for(j = i+1;j<st.length)
		{
			
			if(st.data[i+k]==st.data[j+k])
			{
				int k=0;
				len++;
				while(st.data[i+k]==st.data[j+k])
					len++;	
			}
			else
						
		}
	}
}
