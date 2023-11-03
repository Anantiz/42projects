set logging enabled

# Define a breakpoint at the start of the fill_out_str function.
break get_next_line.c:49

# Define a breakpoint at the start of the resize_str function.
break resize_str
break get_next_line_utils.c:45

# set $variables = { r_buff->size, r_buff->pos, r_buff->str, out->str, out->pos, out->size, str->str, str->size, str->pos, new_str }

run

# Set a display to log the contents of 'out' in fill_out_str.

display r_buff

# Set a display to log the contents of 'str' in resize_str.

continue

display str

continue

continue
continue
continue
continue
continue

continue
continue

continue
continue

continue
continue

continue
continue
