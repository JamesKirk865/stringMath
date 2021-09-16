#include <string>

std::string operator*(std::string s,const int a){//повторяет строку a раз
	std::string d=s;
	for(int i=1;i<a;++i)
		s+=d;
	return s;
}

std::string operator*=(std::string &s,const int a){
	s=s*a;
	return s;
}

std::string operator-(std::string u,std::string v){//если есть возможность вычесть, удаляет подстроку v из u. иначе оставляет прежней
	int pos=u.find(v.c_str());
	if(pos!=std::string::npos)
		for(int i=0;i<v.length();++i)
			u.erase(pos,1);
	return u;
}

std::string operator-=(std::string &u,std::string v){
	u=u-v;
	return u;
}

int operator/(std::string u,std::string v){//считает количество вхождений v в u без ?пересечений? символов
	int pos=0,d,c=0;
	while(true){
		d=u.find(v.c_str(),pos);
		if(d==std::string::npos)
			return c;
		++c;
		pos=d+v.length();
	}
	return -1;
}

std::string operator%(std::string u,std::string v){//удаляет все вхождения подстроки v в u
	while(true){
		if(u.find(v.c_str())==std::string::npos)
			break;
		else
			u=u-v;
	}
	return u;
}

std::string operator%=(std::string &u,std::string v){
	u=u%v;
	return u;
}