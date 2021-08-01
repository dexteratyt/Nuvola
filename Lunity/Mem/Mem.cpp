#include "Mem.h"

uintptr_t Mem::FindMLvlPtr(uintptr_t baseAddr, std::vector<unsigned int> offsets){
    uintptr_t addr = baseAddr;
	for (int I = 0; I < offsets.size(); I++) {
		addr = *(uintptr_t*)(addr);
		if ((uintptr_t*)(addr) == nullptr)
			return addr;
		addr += offsets[I];
	}
	return addr;
}

auto Mem::getModuleBase() -> long long {
    return (long long)GetModuleHandleA(nullptr);
}

auto Mem::getModuleBaseHandle() -> HMODULE {
    return GetModuleHandleA(nullptr);
}

auto Mem::getBaseModuleSize() -> long long {
    MODULEINFO info;
    GetModuleInformation(GetCurrentProcess(), getModuleBaseHandle(), &info, sizeof(info));
    return info.SizeOfImage;
}

auto Mem::getBaseModuleEnd() -> long long {
    return getModuleBase() + getBaseModuleSize();
}

auto Mem::FindSig(const char* pattern) -> uintptr_t {
    return FindSig(getModuleBase(), getBaseModuleEnd(), pattern);
}
struct SearchedSig {
	std::string pattern;
	uintptr_t result;
	SearchedSig(std::string pattern, uintptr_t result) {
		this->pattern = pattern;
		this->result = result;
	}
};

#include "../Utils/Utils.h"

std::vector<SearchedSig> alreadySearched = std::vector<SearchedSig>();
auto Mem::FindSig(long long rangeStart, long long rangeEnd, const char* pattern) -> uintptr_t {
	for(int i = 0; i < alreadySearched.size(); i++) {
		if(alreadySearched[i].pattern == std::string(pattern)) {
			return alreadySearched[i].result;
		}
	}
    const char* pat = pattern;
    long long firstMatch = 0;
    for (long long pCur = rangeStart; pCur < rangeEnd; pCur++) {
        if (!*pat) return firstMatch;
        if (*(PBYTE)pat == '\?' || *(BYTE*)pCur == getByte(pat)) {
            if (!firstMatch) firstMatch = pCur;
            if (!pat[2]) {
				alreadySearched.push_back(SearchedSig(std::string(pattern), firstMatch));
				return firstMatch;
			};
            if (*(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?') pat += 3;
            else pat += 2;
        } else {
            pat = pattern;
            firstMatch = 0;
        }
    }
    return 0;
}

/*
uintptr_t Mem::FindSig(const char* sig){
    const char* pattern = sig;
	uintptr_t firstMatch = 0;
	static const uintptr_t rangeStart = (uintptr_t)GetModuleHandleA("Minecraft.Windows.exe");
	static MODULEINFO miModInfo;
	static bool init = false;
	if (!init) {
		init = true;
		GetModuleInformation(GetCurrentProcess(), (HMODULE)rangeStart, &miModInfo, sizeof(MODULEINFO));
	}
	static const uintptr_t rangeEnd = rangeStart + miModInfo.SizeOfImage;

	BYTE patByte = GET_BYTE(pattern);
	const char* oldPat = pattern;

	for (uintptr_t pCur = rangeStart; pCur < rangeEnd; pCur++)
	{
		if (!*pattern)
			return firstMatch;

		while (*(PBYTE)pattern == ' ')
			pattern++;

		if (!*pattern)
			return firstMatch;

		if (oldPat != pattern) {
			oldPat = pattern;
			if (*(PBYTE)pattern != '\?')
				patByte = GET_BYTE(pattern);
		}

		if (*(PBYTE)pattern == '\?' || *(BYTE*)pCur == patByte)
		{
			if (!firstMatch)
				firstMatch = pCur;

			if (!pattern[2])
				return firstMatch;

			pattern += 2;
		}
		else
		{
			pattern = sig;
			firstMatch = 0;
		}
	}
    return NULL;
}
*/