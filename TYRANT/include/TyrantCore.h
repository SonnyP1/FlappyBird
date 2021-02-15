#pragma once
#ifdef TYRANT_DLL_EXP
	#define TYRANT_API _declspec(dllexport)
#else
	#define TYRANT_API _declspec(dllimport)
#endif