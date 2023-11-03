set logging enabled

# Define a breakpoint at the start of the fill_out_str function.
break get_next_line.c:49
break get_next_line.c:50
break get_next_line.c:55
break get_next_line.c:56
break get_next_line.c:61

# Define a breakpoint at the start of the resize_str function.
break resize_str
break get_next_line_utils.c:45

set $variables = { r_buff->size, r_buff->pos, r_buff->str, out->str, out->pos, out->size, str->str, str->size, str->pos, new_str }

run

# Set a display to log the contents of 'out' in fill_out_str.



# Set a display to log the contents of 'str' in resize_str.

continue
continue
continue



# Continue the execution to hit the breakpoints.
set $j = 1
while $j == 1
	continue
	$i = 0
	while $i < 10
		print($variables[$i])
		$i = $i + 1
	end
end