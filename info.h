#pragma once

#ifdef __cplusplus
extern "C"{
#endif

	// 这个群是否需要抢红包
	int need_skip(const char * grpname, const char * kwds);
	
	// 特定文字是否抢红包
	int dont_open(const char * content, const char * kwds);

	void * rq_create();
	void rq_set(void * rq, const char * key, void * obj);
	void rq_get(void * rq, const char * key, void ** pobj);
	void rq_delete(void * rq);

#ifdef __cplusplus
}

#include <string>
std::string req_find(const char * bytes, size_t len, const char * key0);
#endif
