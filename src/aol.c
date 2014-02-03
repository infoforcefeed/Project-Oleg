/* The MIT License (MIT)
* 
* Copyright (c) 2014 Quinlan Pfiffer, Kyle Terry
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#define DEBUG
#include "aol.h"
#include "oleg.h"
#include "errhandle.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int ol_aol_init(ol_database *db) {
    if (db->is_enabled(OL_F_APPENDONLY, &db->feature_set)) {
        debug("Opening append only log");
        debug("Append only log: %s", db->aol_file);
        db->aolfd = fopen(db->aol_file, "a+");
        check(db->aolfd != NULL, "Error opening append only file");
    }

    return 0;
error:
    return -1;
}

int ol_aol_write_cmd(ol_database *db, const char *cmd, ol_bucket *bucket) {

    fprintf(db->aolfd, ":%d:%s:%zu:%s:%zu:%s\n", 3, cmd, strlen(bucket->key), bucket->key, bucket->data_size, bucket->data_ptr);
    return 0;
}
