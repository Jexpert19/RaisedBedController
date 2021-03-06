/*
 * IO.h
 *
 * Created: 20.07.2020 19:46:47
 *  Author: Jannis Diekmann
 */ 


#ifndef IO_FUNC_H_
#define IO_FUNC_H_


//Basic IO functions:


#undef _BV
#define _BV(b) (1 << (b))
#define TEST(n,b) !!((n)&_BV(b))
#define SBI(n,b) (n |= _BV(b))
#define CBI(n,b) (n &= ~_BV(b))
#define SET_BIT_TO(N,B,TF) do{ if (TF) SBI(N,B); else CBI(N,B); }while(0)
	

#define IO_TEST(n,b) !!((n)&_BV(b))

#define _IO_READ(IO)             TEST(IO ## RPORT, IO ## PIN)

#define _IO_WRITE(IO,V) do{ \
	if (V) SBI(IO ## WPORT, IO ## PIN); \
	else   CBI(IO ## WPORT, IO ## PIN); \
}while(0)

#define _IO_TOGGLE(IO)            (IO ## WPORT ^= _BV(IO ## PIN))

#define _IO_SET_INPUT(IO)         CBI(IO ## DDR, IO ## PIN)
#define _IO_SET_OUTPUT(IO)        SBI(IO ## DDR, IO ## PIN)

#define IO_READ(IO)              _IO_READ(IO)
#define IO_WRITE(IO,V)           _IO_WRITE(IO,V)
#define IO_TOGGLE(IO)            _IO_TOGGLE(IO)

#define IO_SET_INPUT(IO)         _IO_SET_INPUT(IO)
#define IO_INPUT_PULLUP(IO)  do{ _IO_SET_INPUT(IO); _IO_WRITE(IO, HIGH); }while(0)
#define IO_SET_OUTPUT(IO)        _IO_SET_OUTPUT(IO)

#define _IO_ANALOG(IO)           (IO ## ANALOG)

#define IO_ANALOG(IO)            _IO_ANALOG(IO)

#endif /* IO_H_ */