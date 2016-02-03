#pragma once

#ifdef __cplusplus
extern "C"{
#endif

	void send_log(const char * msg, int len = -1);
	void send_multi_log(const char * p);

#ifdef __OBJC__
	void dumpClassInfo(id object);
	void dump(const char * s, NSString * sv);
	void dump_unknown(id obj);
#endif
	
	void dumpi(const char * s, uint64_t code);
	void soundAlert(void);
	
	void sl_printf(const char * fmt, ...);

#ifdef __cplusplus
}
#endif

#define DUMP(s) dump(#s, s)
#define DUMPI(s) dumpi(#s, s)
