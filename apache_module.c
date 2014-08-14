// 참고 URL: http://blog.naver.com/htech79?Redirect=Log&logNo=120119496631
// apache2-dev 를 깐다. apxs 가 생김. 빌드와 디플로이를 해주는 것 같음.
// apxs -c -i -a apache_hello.c libapr.lib libaprutil.lib libapriconv.lib libhttpd.lib
// LoadModule helloworld_module /usr/lib/apache2/modules/apache_hello.so
// SetHandler helloworld

#include <httpd.h>
#include <http_protocol.h>
#include <http_config.h>
 
static int helloworld_handler(request_rec* r)
{
    if (!r->handler || strcmp(r->handler, "helloworld"))
        return DECLINED;
     
    if (r->method_number != M_GET)
        return HTTP_METHOD_NOT_ALLOWED;
     
    ap_set_content_type(r, "text/html;charset=ascii");
    ap_rputs("<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">n", r);
    ap_rputs("<html><head><title>Hello World!</title></head>;", r);
    ap_rputs("<body><h1>Hello World!</h1></body></html>", r);
    return OK;
}
 
static void register_hooks(apr_pool_t* pool)
{
    ap_hook_handler(helloworld_handler, NULL, NULL, APR_HOOK_MIDDLE);
}
 
module AP_MODULE_DECLARE_DATA helloworld_module = {
    STANDARD20_MODULE_STUFF,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    register_hooks
};

