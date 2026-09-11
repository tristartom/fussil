
Inside lldb

```
p/x $fp+8
p/x *(long *)($fp+8)
p/x &buf
#20 = ($fp+8)-&buf
p/x &buf[20] 
p/x *(long *)(&buf[20])
p/x bar
```

```bash
echo "obase=16; ibase=16; B8-A4" | bc
```

