#include "auto.h"

int parse_common_param(char * file_name, unsigned char* out){
    int fd = open(file_name,O_RDONLY);
    if(fd == -1){
        printf("%s%d file:%s not exist\n",__FUNCTION__,__LINE__,file_name);
        return UNEXPECTED;
    }
    off_t file_size;
    char *buffer;
    struct stat stbuf;

    if ((fstat(fd, &stbuf) != 0) || (!S_ISREG(stbuf.st_mode))) {
        printf("%s%d file:%s odd state\n",__FUNCTION__,__LINE__,file_name);
        close(fd);
        return UNEXPECTED;
    }
    char read_buf[MAX_PARAM_LEN];
    char param_buf[MAX_PARAM_LEN];
    file_size = stbuf.st_size;
    if(file_size>MAX_PARAM_LEN){
        printf("%s%d file:%s odd param\n",__FUNCTION__,__LINE__,file_name);
        close(fd);
        return UNEXPECTED;
    }
    int readed = read(fd,read_buf,file_size);
    
    for(int i = 0; i<readed; i++){
        if(read_buf[i]!='#')
            continue;
        else
        {
            for(int j = i; j<readed; j++){
                if(read_buf[j] != '#')
                    param_buf[j] = read_buf[j];
                else{
                    i = j;
                    break;
                }
            }
        }
    }
    *out = atoi(param_buf) & 0xff;
    return SUCCESS;
}

int init(auto_t* handle){
    auto_t* auto_handle = (auto_t*)malloc(sizeof(auto_t));
    if(auto_handle == NULL)
        return NOMEMERY;
    auto_handle->algo_name = g_algo_name[0];
    sprintf(auto_handle->param_file_name,"%s_param",auto_handle->algo_name);
    sprintf(auto_handle->result_file_name,"%s_result.csv",auto_handle->algo_name);
    if(parse_common_param(auto_handle->param_file_name,&(auto_handle->execution_times))){
        free(auto_handle);
        return UNEXPECTED;
    }
    auto_handle->runtime_buffer = 
        (unsigned int*)malloc(sizeof(int)*auto_handle->execution_times);
    if(auto_handle->runtime_buffer == NULL){
        printf("%s%d errcode:%d\n",__FUNCTION__,__LINE__,NOMEMERY);
        return NOMEMERY;
    }
    return SUCCESS;
}

void auto_test(auto_t* handle){
    int err_code = init(handle);
    if(!err_code){
        printf("%s%d errcode:%d\n",__FUNCTION__,__LINE__,err_code);
        return;
    }
        
    while(1){
        

    }
}