#include<iostream>
#include<cstdlib>



//frequent

/*
write malloc32+free32 function:
* malloc32 should always returns an address that is dividable by 32.
* you can't use (modulus operator) %.
* free32 should free the whole allocated space.
* Time Complexity and space Complexity should be O(1)
* assumption: Time and Space Complexity of malloc is O(1).
*/


bool is_It_pow_of_2(size_t num) {
	return !(num & (num - 1));
}


void* alligned_malloc(size_t size, size_t allignment) {
	if (!is_It_pow_of_2(allignment)) return nullptr;

	//Pupose of adding sizeof(size_t) is to store memory address
	size_t adjusted_size = size + allignment + sizeof(size_t);

	void* ptr = std::malloc(adjusted_size);
	std::cout << "Actual addr: " << ptr << "\n";
	//Purpose of adding ptr + size_t:
	//Example: allignment is 2. Ptr address ending with 2.
	// 2 + 4 = 6
	// 6 mask 2 is again 6
	// 6-sizeof(size_t) which is 6 -4 => 2
	// in address 2, we store actual mem addr and addr 6 is passed to applicaiton
	size_t mem_addr = (size_t)ptr + sizeof(size_t);

	size_t modulo_val = mem_addr & (allignment - 1);
	if (modulo_val) {
		mem_addr += (allignment - modulo_val );
	}
	
	size_t* mem = (size_t *)mem_addr - 1;
	*mem = (size_t)ptr;
	return (void*)mem_addr;
}

void aligned_free(void* ptr) {
	size_t *mem_address = (size_t *)ptr;
	--mem_address;
	std::cout << std::hex << "Actual_Addr: " << *mem_address;
	std::free((void*)*mem_address);
}


int main() {
#if 0
	size_t divident;
	size_t divisor;
	size_t quotient;
	size_t remainder;

	std::cout << "divident: ";
	std::cin >> divident;
	std::cout << "divisor: ";
	std::cin >> divisor;
	
	if (is_It_pow_of_2(divisor)) {
		size_t mask = divisor - 1;
		remainder   = divident & mask;  //Modulo
		quotient    = divident & ~mask;

		std::cout << "Remainder: " << remainder << "\n";
		std::cout << "Quotient: " << quotient << "\n";
	}
#endif
	std::string s = "Helloworld";
	char *addr = (char *)alligned_malloc(s.length()+1, 1024);
	
	for (size_t i = 0; i < s.length(); i++) {
		addr[i] = s[i];
	}
	addr[s.length()] = 0;
	std::cout << "Data: " << addr << "\n";
	aligned_free(addr);
	return 0;


}