#include <openssl/opensslv.h>
#include <openssl/crypto.h>
#include <curl/curl.h>
#include <apr_version.h>
#include <jansson.h>
#include <apu_version.h>

int main(int argc, char* argv[])
{
    static char s[4096];

    snprintf(s, sizeof(s),
            "cURL compiled: \"%s\" loaded: \"%s\"; \n\n"
            "OpenSSL compiled: \"%s\" loaded: \"%s\" (\"%s\");\n\n"
            "APR compiled: \"%s\" loaded: \"%s\"; \n\n"
            "APR-UTIL compiled: \"%s\" loaded: \"%s\"; \n\n"
            "jansson compiled: \"%s\"",
            LIBCURL_VERSION, curl_version(),
            OPENSSL_VERSION_TEXT, OpenSSL_version(OPENSSL_VERSION), OpenSSL_version(OPENSSL_CFLAGS),
            APR_VERSION_STRING, apr_version_string(),
            APU_VERSION_STRING, apu_version_string(),
            JANSSON_VERSION
    );
    printf("%s\n", s);

    return 0;
}
