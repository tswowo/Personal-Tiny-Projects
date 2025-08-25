#include<iostream>
#include<string>

template<class T>
class vec{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	private:
		iterator _start=nullptr;
		iterator _finish=nullptr;
		iterator _end_of_storage=nullptr;
	public:
		
		iterator begin(){return _start;}
		iterator end(){return _finish;}
		const_iterator begin()const{return _start;}
		const_iterator end()const{return _finish;}
		
		size_t size()
		{
			return (size_t)(_finish-_start);
		}
		size_t capacity()
		{
			return (size_t)(_end_of_storage-_start);
		}
		bool empty()
		{
			return _finish==_start;
		}
		
		T& operator[](size_t i)
		{
			assert(i<size());
			return _start[i];
		}
		const T& operator[] (size_t i) const
		{
			assert(i<size());
			return _start[i];
		}
		
		void reserve(size_t n)
		{
			if(n>capacity())
			{
				size_t oldsize=size();
				iterator tmp=new T[n];
				for(size_t i=0;i<oldsize;i++)
					tmp[i]=_start[i];
				delete[]_start;
				_start=tmp;
				_finish=tmp+oldsize;
				_end_of_storage=tmp+n;
			}
		}
		void resize(size_t n,T val=T())
		{
			if(n<size())
				_finish=_start+n;
			else
			{
				reserve(n);
				while(_finish<_end_of_storage)
					*(_finish++)=val;
			}
		}
		
		vec(const vec<T>& v)
		{
			reserve(v.size());
			for(auto&x:v)
				push_back(x);
		}
		vec()
		{
			
		}
		vec(size_t size,T val=T())
		{
			reserve(size);
			_finish=_start+size;
			for(iterator it=_start;it<_finish;it++)
				*it=val;
		}
		
		vec<T>& operator =(const vec<T>&v)
		{
			if(this!=&v)
			{
				reserve(v.size());
				for(auto&x:v)
					push_back(x);
			}
			return *this;
		}
		~vec()
		{
			if(_start)
			{
				delete[]_start;
				_start=_finish=_end_of_storage=nullptr;
			}
		}
		void push_back(const T&x)
		{
			if(_finish==_end_of_storage)
				reserve(capacity()==0?4:capacity()*2);
			*(_finish++)=x;
		}
		T back()
		{
			assert(!empty());
			return *(_finish-1);
		}
		void pop_back()
		{
			assert(!empty());
			_finish--;
		}
		void erase(iterator pos)
		{
			assert(pos>=_start);
			assert(pos<=_finish);
			auto it=pos+1;
			while(it<_finish)
			{
				*(it-1)=*it;
				it++;
			}
			_finish--;
		}
		iterator insert(iterator pos,const T&val)
		{
			assert(pos>=_start);
			assert(pos<=_finish);
			if(_finish==_end_of_storage)
			{
				size_t len=pos-_start;
				reserve(capacity()==0?4:capacity()*2);
				pos=_start+len;
			}
			auto it=_finish;
			while(it>pos)
			{
				*(it)=*(it-1);
				it--;
			}
			*pos=val;
			return pos;
		}
		void swap(vec<T>&v)
		{
			std::swap(_start,v._start);
			std::swap(_finish,v._finish);
			std::swap(_end_of_storage,v._end_of_storage);
		}
};

template<class container>
void print_container(const container&v)
{
	for(auto&x:v)
		std::cout<<x<<' ';
	std::cout<<std::endl;
}

int main()
{
	vec<std::string>v;
	v.push_back("11111111111111111111");
	v.push_back("22222222222222222222");
	v.push_back("33333333333333333333");
	v.push_back("44444444444444444444");
	print_container(v);
	v.push_back("11111111111111111111");
	print_container(v);
}
