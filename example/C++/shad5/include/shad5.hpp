#ifndef _SHAD5_h_
#define _SHAD5_h_
#if __cplusplus
extern "C"{
    typedef long sh5_L;
    typedef long* sh5_Lptr;
    void __cdecl encrypt(std::size_t,sh5_Lptr);
    void __cdecl decrypt(std::size_t,sh5_Lptr);
    class shad5{
        private:
        std::size_t __size = 0;
        sh5_Lptr __bytes = (sh5_Lptr)malloc(sizeof(*__bytes)*this->__size);
        
        public:
        shad5(std::size_t __size,sh5_L __bytes[] = nullptr){
            this->__size = __size;
            this->__bytes = __bytes;
        }
        shad5(std::size_t __size,int __bytes[] = nullptr){
            this->__size = __size;
            this->__bytes = (sh5_Lptr)__bytes;
        }
        shad5(){}
        
        const decltype(__bytes) data(){
            return this->__bytes;
        }
        const char* c_data(){
            char *make_ch = nullptr;
            for(size_t i = 0; i < this->__size;++i){
                *(make_ch + i) = this->__bytes[i];
            }
            return make_ch;
        }
        const std::size_t size(){
            return this->__size;
        }
        sh5_Lptr sh5_encrypt(){
            encrypt(this->__size,this->__bytes);
            return this->__bytes;
        }
        sh5_Lptr sh5_encrypt(std::size_t __size,sh5_L __bytes[] = nullptr){
            this->__size = __size;
            this->__bytes = __bytes;
            encrypt(this->__size,this->__bytes);
            return this->__bytes;
        }

        sh5_Lptr sh5_encrypt(std::size_t __size,int __bytes[] = nullptr){
            this->__size = __size;
            this->__bytes = (sh5_Lptr)__bytes;
            encrypt(this->__size,this->__bytes);
            return this->__bytes;
        }

        sh5_Lptr sh5_decrypt(){
            decrypt(this->__size,this->__bytes);
            return this->__bytes;
        }

        operator[](std::size_t i){
            return this->__bytes[i];
        }
    };
}
#endif
#endif