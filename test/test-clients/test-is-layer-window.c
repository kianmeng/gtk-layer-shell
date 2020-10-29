/* This entire file is licensed under MIT
 *
 * Copyright 2020 William Wold
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "test-client-common.h"

static GtkWindow* window_a;
static GtkWindow* window_b;

static void callback_0()
{
    window_a = create_default_window();
    window_b = create_default_window();

    gtk_layer_init_for_window(window_a);

    ASSERT(gtk_layer_is_layer_window(window_a));
    ASSERT(!gtk_layer_is_layer_window(window_b));

    gtk_widget_show_all(GTK_WIDGET(window_a));
    gtk_widget_show_all(GTK_WIDGET(window_b));
}

static void callback_1()
{
    ASSERT(gtk_layer_is_layer_window(window_a));
    ASSERT(!gtk_layer_is_layer_window(window_b));
}

TEST_CALLBACKS(
    callback_0,
    callback_1,
)
