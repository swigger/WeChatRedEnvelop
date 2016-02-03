#pragma once

#ifdef __cplusplus
extern "C"{
#endif

// 这个群是否需要抢红包
int need_skip(const char * grpname);
	
	// 特定文字是否抢红包
	int dont_open(const char * content);

#ifdef __cplusplus
}
#endif
