
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <lua.h>
#include <lauxlib.h>
#include <sys/stat.h>
#include <curl/curl.h>

int l_curl_easy_init(lua_State *L)
{

	CURL *curl = curl_easy_init();

	lua_pushlightuserdata(L, curl);

	return 1;
}

int l_curl_easy_cleanup(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, 1);

	curl_easy_cleanup(curl);

	return 0;
}

int l_curl_easy_perform(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, 1);

	CURLcode code = curl_easy_perform(curl);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_url(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, 1);
	const char *url = lua_tostring(L, 2);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_URL, url);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_header(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	int onoff = lua_toboolean(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_HEADER, onoff);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_netrc(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	lua_Integer level = lua_tointeger(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_NETRC, level);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_netrc_file(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	const char *filename = lua_tostring(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_NETRC_FILE, filename);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_post(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	int post = lua_toboolean(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_POST, post);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_ssl_verifyhost(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	int host = lua_toboolean(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, host);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_ssl_verifypeer(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	int peer = lua_toboolean(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, peer);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_httpget(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	int get = lua_toboolean(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_HTTPGET, get);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_upload(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	int upload = lua_toboolean(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_UPLOAD, upload);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_upload_buffersize(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	lua_Integer size = lua_tointeger(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_UPLOAD_BUFFERSIZE, size);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_infilesize(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	lua_Integer size = lua_tointeger(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_INFILESIZE, size);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_verbose(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	int onoff = lua_toboolean(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_VERBOSE, onoff);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_capath(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	const char *path = lua_tostring(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_CAPATH, path);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_cainfo(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	const char *path = lua_tostring(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_CAINFO, path);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_username(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	const char *username = lua_tostring(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_USERNAME, username);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_password(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	const char *passwd = lua_tostring(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_PASSWORD, passwd);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_postfields(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	const char *fields = lua_tostring(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fields);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_httpheader(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	struct curl_slist *list = (struct curl_slist *)lua_touserdata(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_reset(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -1);

	curl_easy_reset(curl);

	return 0;
}

int l_curl_easy_duphandle(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -1);

	CURL *dup = curl_easy_duphandle(curl);

	lua_pushlightuserdata(L, dup);

	return 1;
}

int l_curl_easy_setopt_aws_sigv4(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	const char *param = lua_tostring(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_AWS_SIGV4, param);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_delete(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	int param = lua_toboolean(L, -1);

	CURLcode code = param ? curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE") : curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "NULL");

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_setopt_customrequest(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	const char *param = lua_tostring(L, -1);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, param);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_slist_empty(lua_State *L)
{

	lua_pushlightuserdata(L, NULL);

	return 1;
}

int l_curl_slist_append(lua_State *L)
{

	struct curl_slist *list = (struct curl_slist *)lua_touserdata(L, -2);
	const char *header = lua_tostring(L, -1);

	list = curl_slist_append(list, header);

	lua_pushlightuserdata(L, (void *)list);

	return 1;
}

int l_curl_slist_free_all(lua_State *L)
{

	struct curl_slist *list = (struct curl_slist *)lua_touserdata(L, -1);

	curl_slist_free_all(list);

	return 0;
}

typedef struct writefunction_memory_s
{
	void *response;
	size_t size;
} writefunction_memory_t;

int l_curl_easy_setopt_writefunction(lua_State *L)
{
	CURL *curl = (CURL *)lua_touserdata(L, 1);

	FILE *tmp = tmpfile();

	CURLcode code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
	CURLcode ccode = curl_easy_setopt(curl, CURLOPT_WRITEDATA, tmp);

	lua_pushinteger(L, code);
	lua_pushlightuserdata(L, tmp);
	lua_pushvalue(L, 2);

	return 3;
}

size_t read_callback(char *buffer, size_t size, size_t nitems, void *userdata)
{

	assert(size == 1); // according to the documentation.

	lua_State *S = (lua_State *)userdata;

	assert(lua_gettop(S) == 2);

	lua_State *L = (lua_State *)lua_touserdata(S, -2);
	assert(L != NULL);

	lua_pushvalue(S, -1); // duplicate the callback function for repeated applications of it.
	lua_xmove(S, L, 1);
	lua_pushinteger(L, nitems);
	lua_call(L, 1, 1);
	const char *substr = lua_tostring(L, -1);
	lua_pop(L, 1);

	size_t len = strlen(substr);

	if (len > 0)
	{
		strcpy(buffer, substr);
		len++; // because `strcpy` also copies the \0 character.
	}

	return len;
}

int l_curl_easy_setopt_readfunction(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2); // the second argument is the callback function
	assert(lua_isfunction(L, -1));

	lua_State *S;
	CURLcode code;

	S = lua_newthread(L);		 // such a new thread is pushed on L also.
	lua_pushlightuserdata(S, L); // put the current state itself
	lua_pushvalue(L, -2);		 // duplicate the given function
	lua_xmove(L, S, 1);			 // then save the doubled reference to the helper state.

	code = curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);

	CURLcode ccode = curl_easy_setopt(curl, CURLOPT_READDATA, S);
	assert(ccode == 0);

	lua_pushinteger(L, code);

	lua_pushvalue(L, -2); // duplicate the working thread
	lua_remove(L, -3);	  // cleanup a doubled value

	return 2;
}

size_t read_callback_filename(char *ptr, size_t size, size_t nmemb, void *userdata)
{
	FILE *readhere = (FILE *)userdata;

	/* copy as much data as possible into the 'ptr' buffer,
	   but no more than 'size' * 'nmemb' bytes! */
	size_t retcode = fread(ptr, size, nmemb, readhere);

	return retcode;
}

int l_curl_easy_setopt_readfunction_filename(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	const char *filename = lua_tostring(L, -1);

	FILE *file = fopen(filename, "rb");

	CURLcode code = curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback_filename);

	CURLcode ccode = curl_easy_setopt(curl, CURLOPT_READDATA, file);
	assert(ccode == 0);

	struct stat st;
	int fd = fileno(file); // get file descriptor
	fstat(fd, &st);
	off_t size = st.st_size;
	ccode = curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, size);
	assert(ccode == CURLE_OK);

	lua_pushinteger(L, code);
	lua_pushlightuserdata(L, file);

	return 2;
}

size_t read_callback_string(char *ptr, size_t size, size_t nmemb, void *userdata)
{
	assert(size == 1);

	lua_State *L = (lua_State *)userdata;
	const char *response = lua_tostring(L, -2);
	int len = lua_tointeger(L, -1);

	lua_pop(L, 2); // remove the size from the stack.

	size_t n = len;

	if (n > 0)
	{

		n = n < nmemb ? n : nmemb;

		char *copied = strncpy(ptr, response, n);

		assert(copied == ptr); // according to the documentation

		lua_pushlightuserdata(L, (void *)(response + n));
		lua_pushinteger(L, len - n);
	}
	else
	{
		n = 0;						// to protect against negative values.
		lua_pop(L, 2);				// pop both the reference to the original state and string.
		assert(lua_gettop(L) == 0); // ensure the cleaning.
	}

	/*
	printf("readfunction_string: asked for %d of %d: %s\n", (int)n, (int)nmemb, ptr);
	fflush(stdout);
	*/

	return n;
}

int l_curl_easy_setopt_readfunction_string(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	const char *str = lua_tostring(L, -1);
	int size = strlen(str);

	lua_State *S = lua_newthread(L);	 // such a new thread is pushed on L also.
	lua_pushlightuserdata(S, (void *)L); // put the current state itself.
	lua_pushvalue(L, -2);				 // duplicate the reference to the given string.
	lua_pushvalue(L, -1);				 // put two copies, the first to stop the gc and the second is the working one.
	lua_xmove(L, S, 2);					 // then save the doubled reference to the helper state.
	lua_pushinteger(S, size);			 // also put on the auxiliary state the size of the string.

	CURLcode code = curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback_string);

	CURLcode ccode = curl_easy_setopt(curl, CURLOPT_READDATA, S);
	assert(ccode == CURLE_OK);

	lua_pushinteger(L, code);
	lua_pushlightuserdata(L, S); // now we return the reference to the new `thread`.

	return 2;
}

int l_curl_easy_getopt_writedata(lua_State *L)
{

	FILE *tmp = (FILE *)lua_touserdata(L, 1);

	fseek(tmp, 0L, SEEK_END);
	size_t sz = ftell(tmp);
	rewind(tmp);

	char buffer[sz];

	size_t r = fread(buffer, 1, sz, tmp);

	fclose(tmp);

	lua_checkstack(L, 3);
	lua_pushboolean(L, r == sz);
	lua_pushlstring(L, buffer, r);
	lua_pushinteger(L, r);

	return 3;
}

int l_curl_easy_getinfo_response_code(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -1);

	long response_code;
	CURLcode code = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

	lua_pushinteger(L, code);
	lua_pushinteger(L, response_code);

	return 2;
}

int l_curl_version(lua_State *L)
{

	char *version = curl_version();

	lua_pushstring(L, version);

	return 1;
}

int l_curl_getdate(lua_State *L)
{

	const char *datestr = lua_tostring(L, -1);
	time_t t = curl_getdate(datestr, NULL);

	lua_pushinteger(L, t);

	return 1;
}

int l_curl_easy_escape(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	size_t l;
	const char *str = lua_tolstring(L, -1, &l);

	char *encoded = curl_easy_escape(curl, str, l);

	lua_pushstring(L, encoded);

	curl_free(encoded);

	return 1;
}

int l_curl_easy_setopt_accept_encoding(lua_State *L)
{
	CURL *curl = (CURL *)lua_touserdata(L, 1);
	const char *str = lua_tostring(L, 2);

	CURLcode code = curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, str);

	lua_pushinteger(L, code);

	return 1;
}

int l_curl_easy_unescape(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, -2);
	const char *str = lua_tostring(L, -1);
	int size;

	char *decoded = curl_easy_unescape(curl, str, 0, &size);

	lua_pushstring(L, decoded);
	lua_pushinteger(L, size);

	curl_free(decoded);

	return 2;
}

int l_curl_free(lua_State *L)
{
	const char *str = lua_tostring(L, -1);
	curl_free((char *)str);

	return 0;
}

int l_libc_free(lua_State *L)
{
	void *p = lua_touserdata(L, -1);
	free(p);

	return 0;
}

int l_liblua_lua_close(lua_State *L)
{
	lua_State *S = (lua_State *)lua_touserdata(L, -1);
	lua_close(S);

	return 0;
}

int l_libc_fclose(lua_State *L)
{
	FILE *p = (FILE *)lua_touserdata(L, -1);
	int r = fclose(p);

	lua_pushinteger(L, r);

	return 1;
}

int l_test(lua_State *L)
{
	lua_State *S = lua_newthread(L); // such a new thread is pushed on L also.
	lua_Integer i = lua_tointeger(L, -2);
	lua_pushinteger(S, i);
	assert(lua_tointeger(S, -1) == 42);
	return 1;
}

int l_test_func(lua_State *L)
{
	lua_State *S = lua_newthread(L); // such a new thread is pushed on L also.
	lua_pushvalue(L, -2);			 // duplicate the given function
	lua_xmove(L, S, 1);
	return 1; // the thread actually
}

int l_curl_easy_header(lua_State *L)
{

	CURL *curl = (CURL *)lua_touserdata(L, 1);

	lua_Integer request = lua_type(L, 2) == LUA_TNUMBER ? lua_tointeger(L, 2) : 0;

	struct curl_header *prev = NULL;
	struct curl_header *h;

	lua_newtable(L);

	/* extract the normal headers from the first request */
	while ((h = curl_easy_nextheader(curl, CURLH_HEADER | CURLH_TRAILER, request, prev)))
	{
		lua_pushstring(L, h->value);
		lua_setfield(L, -2, h->name);
		prev = h;
	}

	return 1;
}

/*
	Registration phase starts
*/

const struct luaL_Reg libcurl[] = {
	{"curl_easy_init", l_curl_easy_init},
	{"curl_easy_cleanup", l_curl_easy_cleanup},
	{"curl_easy_reset", l_curl_easy_reset},
	{"curl_easy_duphandle", l_curl_easy_duphandle},
	{"curl_easy_setopt_url", l_curl_easy_setopt_url},
	{"curl_easy_setopt_header", l_curl_easy_setopt_header},
	{"curl_easy_setopt_netrc", l_curl_easy_setopt_netrc},
	{"curl_easy_setopt_netrc_file", l_curl_easy_setopt_netrc_file},
	{"curl_easy_setopt_post", l_curl_easy_setopt_post},
	{"curl_easy_setopt_ssl_verifyhost", l_curl_easy_setopt_ssl_verifyhost},
	{"curl_easy_setopt_ssl_verifypeer", l_curl_easy_setopt_ssl_verifypeer},
	{"curl_easy_setopt_upload", l_curl_easy_setopt_upload},
	{"curl_easy_setopt_upload_buffersize", l_curl_easy_setopt_upload_buffersize},
	{"curl_easy_setopt_infilesize", l_curl_easy_setopt_infilesize},
	{"curl_easy_setopt_httpget", l_curl_easy_setopt_httpget},
	{"curl_easy_setopt_verbose", l_curl_easy_setopt_verbose},
	{"curl_easy_setopt_capath", l_curl_easy_setopt_capath},
	{"curl_easy_setopt_cainfo", l_curl_easy_setopt_cainfo},
	{"curl_easy_setopt_username", l_curl_easy_setopt_username},
	{"curl_easy_setopt_password", l_curl_easy_setopt_password},
	{"curl_easy_setopt_postfields", l_curl_easy_setopt_postfields},
	{"curl_easy_setopt_httpheader", l_curl_easy_setopt_httpheader},
	{"curl_easy_setopt_writefunction", l_curl_easy_setopt_writefunction},
	{"curl_easy_setopt_readfunction", l_curl_easy_setopt_readfunction},
	{"curl_easy_setopt_readfunction_filename", l_curl_easy_setopt_readfunction_filename},
	{"curl_easy_setopt_readfunction_string", l_curl_easy_setopt_readfunction_string},
	{"curl_easy_setopt_aws_sigv4", l_curl_easy_setopt_aws_sigv4},
	{"curl_easy_setopt_customrequest", l_curl_easy_setopt_customrequest},
	{"curl_easy_setopt_delete", l_curl_easy_setopt_delete},
	{"curl_easy_setopt_accept_encoding", l_curl_easy_setopt_accept_encoding},
	{"curl_easy_getinfo_response_code", l_curl_easy_getinfo_response_code},
	{"curl_easy_getopt_writedata", l_curl_easy_getopt_writedata},
	{"curl_easy_perform", l_curl_easy_perform},
	{"curl_slist_empty", l_curl_slist_empty},
	{"curl_slist_append", l_curl_slist_append},
	{"curl_slist_free_all", l_curl_slist_free_all},
	{"curl_version", l_curl_version},
	{"curl_getdate", l_curl_getdate},
	{"curl_easy_escape", l_curl_easy_escape},
	{"curl_easy_unescape", l_curl_easy_unescape},
	{"curl_easy_header", l_curl_easy_header},
	{"libc_free", l_libc_free},
	{"libc_fclose", l_libc_fclose},
	{"liblua_lua_close", l_liblua_lua_close},
	{"curl_free", l_curl_free},
	{"test", l_test},
	{"test_func", l_test_func},
	{NULL, NULL} /* sentinel */
};

void enum_CURL_NETRC_OPTION(lua_State *L)
{

	lua_newtable(L);

	lua_pushinteger(L, CURL_NETRC_IGNORED);
	lua_setfield(L, -2, "CURL_NETRC_IGNORED");
	lua_pushinteger(L, CURL_NETRC_OPTIONAL);
	lua_setfield(L, -2, "CURL_NETRC_OPTIONAL");
	lua_pushinteger(L, CURL_NETRC_REQUIRED);
	lua_setfield(L, -2, "CURL_NETRC_REQUIRED");
	lua_pushinteger(L, CURL_NETRC_LAST);
	lua_setfield(L, -2, "CURL_NETRC_LAST");

	lua_setfield(L, -2, "CURL_NETRC_OPTION");
}

void enum_CURLcode(lua_State *L)
{

	lua_newtable(L);

	lua_pushinteger(L, CURLE_OK);
	lua_setfield(L, -2, "OK");

	lua_pushinteger(L, CURLE_UNSUPPORTED_PROTOCOL);
	lua_setfield(L, -2, "UNSUPPORTED_PROTOCOL");

	lua_pushinteger(L, CURLE_FAILED_INIT);
	lua_setfield(L, -2, "FAILED_INIT");

	lua_pushinteger(L, CURLE_URL_MALFORMAT);
	lua_setfield(L, -2, "URL_MALFORMAT");

	lua_pushinteger(L, CURLE_NOT_BUILT_IN);
	lua_setfield(L, -2, "NOT_BUILT_IN");

	lua_pushinteger(L, CURLE_COULDNT_RESOLVE_PROXY);
	lua_setfield(L, -2, "COULDNT_RESOLVE_PROXY");

	lua_pushinteger(L, CURLE_COULDNT_RESOLVE_HOST);
	lua_setfield(L, -2, "COULDNT_RESOLVE_HOST");

	lua_pushinteger(L, CURLE_COULDNT_CONNECT);
	lua_setfield(L, -2, "COULDNT_CONNECT");

	lua_pushinteger(L, CURLE_WEIRD_SERVER_REPLY);
	lua_setfield(L, -2, "WEIRD_SERVER_REPLY");

	lua_pushinteger(L, CURLE_REMOTE_ACCESS_DENIED);
	lua_setfield(L, -2, "REMOTE_ACCESS_DENIED");

	lua_pushinteger(L, CURLE_FTP_ACCEPT_FAILED);
	lua_setfield(L, -2, "FTP_ACCEPT_FAILED");

	lua_pushinteger(L, CURLE_FTP_WEIRD_PASS_REPLY);
	lua_setfield(L, -2, "FTP_WEIRD_PASS_REPLY");

	lua_pushinteger(L, CURLE_FTP_ACCEPT_TIMEOUT);
	lua_setfield(L, -2, "FTP_ACCEPT_TIMEOUT");

	lua_pushinteger(L, CURLE_FTP_WEIRD_PASV_REPLY);
	lua_setfield(L, -2, "FTP_WEIRD_PASV_REPLY");

	lua_pushinteger(L, CURLE_FTP_WEIRD_227_FORMAT);
	lua_setfield(L, -2, "FTP_WEIRD_227_FORMAT");

	lua_pushinteger(L, CURLE_FTP_CANT_GET_HOST);
	lua_setfield(L, -2, "FTP_CANT_GET_HOST");

	lua_pushinteger(L, CURLE_HTTP2);
	lua_setfield(L, -2, "HTTP2");

	lua_pushinteger(L, CURLE_FTP_COULDNT_SET_TYPE);
	lua_setfield(L, -2, "FTP_COULDNT_SET_TYPE");

	lua_pushinteger(L, CURLE_PARTIAL_FILE);
	lua_setfield(L, -2, "PARTIAL_FILE");

	lua_pushinteger(L, CURLE_FTP_COULDNT_RETR_FILE);
	lua_setfield(L, -2, "FTP_COULDNT_RETR_FILE");

	lua_pushinteger(L, CURLE_OBSOLETE20);
	lua_setfield(L, -2, "OBSOLETE20");

	lua_pushinteger(L, CURLE_QUOTE_ERROR);
	lua_setfield(L, -2, "QUOTE_ERROR");

	lua_pushinteger(L, CURLE_HTTP_RETURNED_ERROR);
	lua_setfield(L, -2, "HTTP_RETURNED_ERROR");

	lua_pushinteger(L, CURLE_WRITE_ERROR);
	lua_setfield(L, -2, "WRITE_ERROR");

	lua_pushinteger(L, CURLE_OBSOLETE24);
	lua_setfield(L, -2, "OBSOLETE24");

	lua_pushinteger(L, CURLE_UPLOAD_FAILED);
	lua_setfield(L, -2, "UPLOAD_FAILED");

	lua_pushinteger(L, CURLE_READ_ERROR);
	lua_setfield(L, -2, "READ_ERROR");

	lua_pushinteger(L, CURLE_OUT_OF_MEMORY);
	lua_setfield(L, -2, "OUT_OF_MEMORY");

	lua_pushinteger(L, CURLE_OPERATION_TIMEDOUT);
	lua_setfield(L, -2, "OPERATION_TIMEDOUT");

	lua_pushinteger(L, CURLE_OBSOLETE29);
	lua_setfield(L, -2, "OBSOLETE29");

	lua_pushinteger(L, CURLE_FTP_PORT_FAILED);
	lua_setfield(L, -2, "FTP_PORT_FAILED");

	lua_pushinteger(L, CURLE_FTP_COULDNT_USE_REST);
	lua_setfield(L, -2, "FTP_COULDNT_USE_REST");

	lua_pushinteger(L, CURLE_OBSOLETE32);
	lua_setfield(L, -2, "OBSOLETE32");

	lua_pushinteger(L, CURLE_RANGE_ERROR);
	lua_setfield(L, -2, "RANGE_ERROR");

	lua_pushinteger(L, CURLE_HTTP_POST_ERROR);
	lua_setfield(L, -2, "HTTP_POST_ERROR");

	lua_pushinteger(L, CURLE_SSL_CONNECT_ERROR);
	lua_setfield(L, -2, "SSL_CONNECT_ERROR");

	lua_pushinteger(L, CURLE_BAD_DOWNLOAD_RESUME);
	lua_setfield(L, -2, "BAD_DOWNLOAD_RESUME");

	lua_pushinteger(L, CURLE_FILE_COULDNT_READ_FILE);
	lua_setfield(L, -2, "FILE_COULDNT_READ_FILE");

	lua_pushinteger(L, CURLE_LDAP_CANNOT_BIND);
	lua_setfield(L, -2, "LDAP_CANNOT_BIND");

	lua_pushinteger(L, CURLE_LDAP_SEARCH_FAILED);
	lua_setfield(L, -2, "LDAP_SEARCH_FAILED");

	lua_pushinteger(L, CURLE_OBSOLETE40);
	lua_setfield(L, -2, "OBSOLETE40");

	lua_pushinteger(L, CURLE_FUNCTION_NOT_FOUND);
	lua_setfield(L, -2, "FUNCTION_NOT_FOUND");

	lua_pushinteger(L, CURLE_ABORTED_BY_CALLBACK);
	lua_setfield(L, -2, "ABORTED_BY_CALLBACK");

	lua_pushinteger(L, CURLE_BAD_FUNCTION_ARGUMENT);
	lua_setfield(L, -2, "BAD_FUNCTION_ARGUMENT");

	lua_pushinteger(L, CURLE_OBSOLETE44);
	lua_setfield(L, -2, "OBSOLETE44");

	lua_pushinteger(L, CURLE_INTERFACE_FAILED);
	lua_setfield(L, -2, "INTERFACE_FAILED");

	lua_pushinteger(L, CURLE_OBSOLETE46);
	lua_setfield(L, -2, "OBSOLETE46");

	lua_pushinteger(L, CURLE_TOO_MANY_REDIRECTS);
	lua_setfield(L, -2, "TOO_MANY_REDIRECTS");

	lua_pushinteger(L, CURLE_UNKNOWN_OPTION);
	lua_setfield(L, -2, "UNKNOWN_OPTION");

	lua_pushinteger(L, CURLE_SETOPT_OPTION_SYNTAX);
	lua_setfield(L, -2, "SETOPT_OPTION_SYNTAX");

	lua_pushinteger(L, CURLE_OBSOLETE50);
	lua_setfield(L, -2, "OBSOLETE50");

	lua_pushinteger(L, CURLE_OBSOLETE51);
	lua_setfield(L, -2, "OBSOLETE51");

	lua_pushinteger(L, CURLE_GOT_NOTHING);
	lua_setfield(L, -2, "GOT_NOTHING");

	lua_pushinteger(L, CURLE_SSL_ENGINE_NOTFOUND);
	lua_setfield(L, -2, "SSL_ENGINE_NOTFOUND");

	lua_pushinteger(L, CURLE_SSL_ENGINE_SETFAILED);
	lua_setfield(L, -2, "SSL_ENGINE_SETFAILED");

	lua_pushinteger(L, CURLE_SEND_ERROR);
	lua_setfield(L, -2, "SEND_ERROR");

	lua_pushinteger(L, CURLE_RECV_ERROR);
	lua_setfield(L, -2, "RECV_ERROR");

	lua_pushinteger(L, CURLE_OBSOLETE57);
	lua_setfield(L, -2, "OBSOLETE57");

	lua_pushinteger(L, CURLE_SSL_CERTPROBLEM);
	lua_setfield(L, -2, "SSL_CERTPROBLEM");

	lua_pushinteger(L, CURLE_SSL_CIPHER);
	lua_setfield(L, -2, "SSL_CIPHER");

	lua_pushinteger(L, CURLE_PEER_FAILED_VERIFICATION);
	lua_setfield(L, -2, "PEER_FAILED_VERIFICATION");

	lua_pushinteger(L, CURLE_SSL_CACERT);
	lua_setfield(L, -2, "SSL_CACERT");

	lua_pushinteger(L, CURLE_BAD_CONTENT_ENCODING);
	lua_setfield(L, -2, "BAD_CONTENT_ENCODING");

	lua_pushinteger(L, CURLE_FILESIZE_EXCEEDED);
	lua_setfield(L, -2, "FILESIZE_EXCEEDED");

	lua_pushinteger(L, CURLE_USE_SSL_FAILED);
	lua_setfield(L, -2, "USE_SSL_FAILED");

	lua_pushinteger(L, CURLE_SEND_FAIL_REWIND);
	lua_setfield(L, -2, "SEND_FAIL_REWIND");

	lua_pushinteger(L, CURLE_SSL_ENGINE_INITFAILED);
	lua_setfield(L, -2, "SSL_ENGINE_INITFAILED");

	lua_pushinteger(L, CURLE_LOGIN_DENIED);
	lua_setfield(L, -2, "LOGIN_DENIED");

	lua_pushinteger(L, CURLE_TFTP_NOTFOUND);
	lua_setfield(L, -2, "TFTP_NOTFOUND");

	lua_pushinteger(L, CURLE_TFTP_PERM);
	lua_setfield(L, -2, "TFTP_PERM");

	lua_pushinteger(L, CURLE_REMOTE_DISK_FULL);
	lua_setfield(L, -2, "REMOTE_DISK_FULL");

	lua_pushinteger(L, CURLE_TFTP_ILLEGAL);
	lua_setfield(L, -2, "TFTP_ILLEGAL");

	lua_pushinteger(L, CURLE_TFTP_UNKNOWNID);
	lua_setfield(L, -2, "TFTP_UNKNOWNID");

	lua_pushinteger(L, CURLE_REMOTE_FILE_EXISTS);
	lua_setfield(L, -2, "REMOTE_FILE_EXISTS");

	lua_pushinteger(L, CURLE_TFTP_NOSUCHUSER);
	lua_setfield(L, -2, "TFTP_NOSUCHUSER");

	lua_pushinteger(L, CURLE_SSL_CACERT_BADFILE);
	lua_setfield(L, -2, "SSL_CACERT_BADFILE");

	lua_pushinteger(L, CURLE_REMOTE_FILE_NOT_FOUND);
	lua_setfield(L, -2, "REMOTE_FILE_NOT_FOUND");

	lua_pushinteger(L, CURLE_SSH);
	lua_setfield(L, -2, "SSH");

	lua_pushinteger(L, CURLE_SSL_SHUTDOWN_FAILED);
	lua_setfield(L, -2, "SSL_SHUTDOWN_FAILED");

	lua_pushinteger(L, CURLE_AGAIN);
	lua_setfield(L, -2, "AGAIN");

	lua_pushinteger(L, CURLE_SSL_CRL_BADFILE);
	lua_setfield(L, -2, "SSL_CRL_BADFILE");

	lua_pushinteger(L, CURLE_SSL_ISSUER_ERROR);
	lua_setfield(L, -2, "SSL_ISSUER_ERROR");

	lua_pushinteger(L, CURLE_FTP_PRET_FAILED);
	lua_setfield(L, -2, "FTP_PRET_FAILED");

	lua_pushinteger(L, CURLE_RTSP_CSEQ_ERROR);
	lua_setfield(L, -2, "RTSP_CSEQ_ERROR");

	lua_pushinteger(L, CURLE_RTSP_SESSION_ERROR);
	lua_setfield(L, -2, "RTSP_SESSION_ERROR");

	lua_pushinteger(L, CURLE_FTP_BAD_FILE_LIST);
	lua_setfield(L, -2, "FTP_BAD_FILE_LIST");

	lua_pushinteger(L, CURLE_CHUNK_FAILED);
	lua_setfield(L, -2, "CHUNK_FAILED");

	lua_pushinteger(L, CURLE_NO_CONNECTION_AVAILABLE);
	lua_setfield(L, -2, "NO_CONNECTION_AVAILABLE");

	lua_pushinteger(L, CURLE_SSL_PINNEDPUBKEYNOTMATCH);
	lua_setfield(L, -2, "SSL_PINNEDPUBKEYNOTMATCH");

	lua_pushinteger(L, CURLE_SSL_INVALIDCERTSTATUS);
	lua_setfield(L, -2, "SSL_INVALIDCERTSTATUS");

	lua_pushinteger(L, CURLE_HTTP2_STREAM);
	lua_setfield(L, -2, "HTTP2_STREAM");

	lua_pushinteger(L, CURLE_RECURSIVE_API_CALL);
	lua_setfield(L, -2, "RECURSIVE_API_CALL");

	lua_pushinteger(L, CURLE_AUTH_ERROR);
	lua_setfield(L, -2, "AUTH_ERROR");

	lua_pushinteger(L, CURLE_HTTP3);
	lua_setfield(L, -2, "HTTP3");

	lua_pushinteger(L, CURLE_QUIC_CONNECT_ERROR);
	lua_setfield(L, -2, "QUIC_CONNECT_ERROR");

	lua_pushinteger(L, CURLE_PROXY);
	lua_setfield(L, -2, "PROXY");

	lua_pushinteger(L, CURLE_SSL_CLIENTCERT);
	lua_setfield(L, -2, "SSL_CLIENTCERT");

	lua_pushinteger(L, CURL_LAST);
	lua_setfield(L, -2, "LAST");

	lua_setfield(L, -2, "CURLcode");
}

int luaopen_libcurllua(lua_State *L)
{
	luaL_newlib(L, libcurl);

	enum_CURLcode(L);
	enum_CURL_NETRC_OPTION(L);

	lua_pushlightuserdata(L, NULL);
	lua_setfield(L, -2, "NULL");

	return 1;
}
