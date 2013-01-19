// Copyright 2013 Martin Pool

#include <stdlib.h>
#include <string.h>

#include "loss.h"

// Construct a new token containing one character
loss_buf *loss_buf_char(char ch) {
    loss_buf *tok = malloc(sizeof *tok);
    tok->n = 1;
    tok->s = strndup(&ch, 1);
    return tok;
}


loss_object *loss_string_strz(const char *s) {
    loss_object *o = calloc(1, sizeof *o);
    o->type = STRING;
    o->val.string = strdup(s);
    return o;
}


// Append one character to an existing token.
void loss_buf_push(loss_buf *tok, char ch) {
    // n is one-based; string indexes are 0-based.
    size_t new_char_index = tok->n;
    size_t new_nul_index = new_char_index + 1;
    size_t new_buf_size = new_nul_index + 1;
    tok->s = realloc(tok->s, new_buf_size);
    tok->s[new_char_index] = ch;
    tok->s[new_nul_index] = 0;
    tok->n++;
}


void loss_buf_free(loss_buf *tok) {
    free(tok->s);
    free(tok);
}
