#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../php_screw.h"
#include "../my_screw.h"

main(int argc, char**argv)
{
	FILE	*fp;
	struct	stat	stat_buf;
	char	*datap, *newdatap, buf[PM9SCREW_LEN + 1];
	int	datalen, newdatalen;
	int	cryptkey_len = sizeof pm9screw_mycryptkey / 2;
	char	oldfilename[256];
	int	i;

	if (argc != 2) {
		fprintf(stderr, "Usage: filename.\n");
		exit(0);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "File not found(%s)\n", argv[1]);
		exit(0);
	}

    fread(buf, PM9SCREW_LEN, 1, fp);
    if (memcmp(buf, PM9SCREW, PM9SCREW_LEN) != 0) {
        fclose(fp);
        fprintf(stderr, "%s can't decode ", argv[1]);
        exit(0);
    }

	fstat(fileno(fp), &stat_buf);
	datalen = stat_buf.st_size - PM9SCREW_LEN;
	datap = (char*)malloc(datalen);
	fread(datap, datalen, 1, fp);
	fclose(fp);


	for(i=0; i<datalen; i++) {
		datap[i] = (char)pm9screw_mycryptkey[(datalen - i) % cryptkey_len] ^ (~(datap[i]));
	}
	newdatap = zdecode(datap, datalen, &newdatalen);

    sprintf(oldfilename,"%s.src",argv[1]);
	fp = fopen(oldfilename, "w");
	if (fp == NULL) {
		fprintf(stderr, "Can not create decode file(%s)\n", oldfilename);
		exit(0);
	}
	fwrite(newdatap, newdatalen, 1, fp);
	fclose(fp);
	fprintf(stderr, "Success decode(%s)\n", argv[1]);
	free(newdatap);
	free(datap);
}
