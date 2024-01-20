#ifndef DEFINES_H
#define DEFINES_H

#define SAFE_DELETE(x)	\
	if(x != nullptr)	\
	{					\
		delete x;		\
		x = nullptr;	\
	}

#define FINALIZE_DELETE(x)	\
	if(x != nullptr)		\
	{						\
		x->Finalize();		\
		delete x;			\
		x = nullptr;		\
	}

#define GET_ARR_LENGTH(arr, type) (sizeof(arr) / sizeof(type))

#define GET_ARR_PTR_LENGTH(ptr) (sizeof(ptr)/sizeof(ptr[0]))


#define PROVE_RESULT(x) \
{						\
	if(x != 0) return x;\
}

#endif // !DEFINES_H
