#include <cstdio>
typedef unsigned int ull;
inline ull max(ull a,ull b){
	return a>b?b:a;
}
#define size 1000000
struct hp{
	ull pre[size],len,i,t,p,q;
	inline void add(hp *b,hp *tp){
		t=max(len,b->len);
		p=0;
		for(i=0;i<t;++i){
			tp->pre[i]=pre[i]+p+b->pre[i];
			p=tp->pre[i]>>31;
			tp->pre[i]=tp->pre[i]&0x7fffffff;
		}
		if(p) tp->pre[i]=p,++i;
		tp->len=i;
	}
	void sub(hp *b,hp *tp){
		t=max(len,b->len);
		p=0;
		for(i=0;i<t;++i){
			tp->pre[i]=pre[i]-p-b->pre[i];
			p=tp->pre[i]>>31;
			tp->pre[i]=tp->pre[i]&0x7fffffff;
		}
		if(p) while(i<size){
			tp->pre[i]=0x7fffffff;
			++i;
		}
		tp->len=i;
	}
	inline char cmp(hp *b){
		if(len<b->len) return 0;
		if(len>b->len) return 2;
		i=len;
		while(i){
			--i;
			if(pre[i]<b->pre[i]) return 0;
			if(pre[i]>b->pre[i]) return 2;
		}
		return 1;
	}
	inline bool greaterThan(hp *b){
		return cmp(b)==2;
	}
	inline bool smallerThan(hp *b){
		return cmp(b)==0;
	}
	inline bool smallerEqualThan(hp *b){
		return cmp(b)!=2;
	}
	inline bool greaterEqualThan(hp *b){
		return cmp(b);
	}
	inline bool same(hp *b){
		return cmp(b)==1;
	}
};
inline bool operator>(hp a,hp b){
	return a.cmp(b)==2;
}
inline bool operator<(hp a,hp b){
	return a.cmp(b)==0;
}
inline bool operator>=(hp a,hp b){
	return a.cmp(b);
}
inline bool operator<=(hp a,hp b){
	return a.cmp(b)!=2;
}
inline bool operator==(hp a,hp b){
	return a.cmp(b)==1;
}
typedef hp unsigned_hp;
