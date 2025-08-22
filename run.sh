export OUTDIR=out
EXE=${OUTDIR}/ext2-fuse
IMG=${OUTDIR}/ext2.img
MNTPNT=${OUTDIR}/mnt
CMPCMDS=${OUTDIR}/compile_commands.json

if [ -f $CMPCMDS ]; then
    make -s -j8
else
    ./gen/compile_commands
fi

rm -f $IMG
dd if=/dev/zero of=$IMG bs=8M count=1 status=none
mkfs.ext2 -q $IMG
mkdir -p $MNTPNT
$EXE -f -s $IMG $MNTPNT
