# ETC

Not important but related in android.

## print temperature

Print battery's temperature in every 5 seconds.

```shell
$ watch -n 5 dumpsys battery | grep temperature
```