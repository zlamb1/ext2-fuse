#include <errno.h>
#include <stdio.h>

#include "ext2.h"

#define UNIMPL(NAME)                                                          \
  fprintf (stderr, "ext2: %s not implemented\n", NAME);                       \
  return -ENOSYS

void *
ext2_init (struct fuse_conn_info *conn)
{
  (void) conn;
  return NULL;
}

void
ext2_destroy (void *private_data)
{
  (void) private_data;
}

int
ext2_getattr (const char *path, struct stat *stbuf)
{
  (void) path;
  (void) stbuf;
  UNIMPL ("getattr");
}

int
ext2_fgetattr (const char *path, struct stat *stbuf, struct fuse_file_info *fi)
{
  (void) path;
  (void) stbuf;
  (void) fi;
  UNIMPL ("fgetattr");
}

int
ext2_access (const char *path, int mask)
{
  (void) path;
  (void) mask;
  UNIMPL ("access");
}

int
ext2_readlink (const char *path, char *buf, size_t size)
{
  (void) path;
  (void) buf;
  (void) size;
  UNIMPL ("readlink");
}

int
ext2_opendir (const char *path, struct fuse_file_info *fi)
{
  (void) path;
  (void) fi;
  UNIMPL ("opendir");
}

int
ext2_readdir (const char *path, void *buf, fuse_fill_dir_t filler,
              off_t offset, struct fuse_file_info *fi)
{
  (void) path;
  (void) buf;
  (void) filler;
  (void) offset;
  (void) fi;
  UNIMPL ("readdir");
}

int
ext2_mknod (const char *path, mode_t mode, dev_t rdev)
{
  (void) path;
  (void) mode;
  (void) rdev;
  UNIMPL ("mknod");
}

int
ext2_mkdir (const char *path, mode_t mode)
{
  (void) path;
  (void) mode;
  UNIMPL ("mkdir");
}

int
ext2_unlink (const char *path)
{
  (void) path;
  UNIMPL ("unlink");
}

int
ext2_rmdir (const char *path)
{
  (void) path;
  UNIMPL ("rmdir");
}

int
ext2_symlink (const char *to, const char *from)
{
  (void) to;
  (void) from;
  UNIMPL ("symlink");
}

int
ext2_rename (const char *from, const char *to)
{
  (void) from;
  (void) to;
  UNIMPL ("rename");
}

int
ext2_link (const char *from, const char *to)
{
  (void) from;
  (void) to;
  UNIMPL ("link");
}

int
ext2_chmod (const char *path, mode_t mode)
{
  (void) path;
  (void) mode;
  UNIMPL ("chmod");
}

int
ext2_chown (const char *path, uid_t uid, gid_t gid)
{
  (void) path;
  (void) uid;
  (void) gid;
  UNIMPL ("chown");
}

int
ext2_truncate (const char *path, off_t size)
{
  (void) path;
  (void) size;
  UNIMPL ("truncate");
}

int
ext2_ftruncate (const char *path, off_t size, struct fuse_file_info *fi)
{
  (void) path;
  (void) size;
  (void) fi;
  UNIMPL ("ftruncate");
}

int
ext2_utimens (const char *path, const struct timespec ts[2])
{
  (void) path;
  (void) ts;
  UNIMPL ("utimens");
}

int
ext2_create (const char *path, mode_t mode, struct fuse_file_info *fi)
{
  (void) path;
  (void) mode;
  (void) fi;
  UNIMPL ("create");
}

int
ext2_open (const char *path, struct fuse_file_info *fi)
{
  (void) path;
  (void) fi;
  UNIMPL ("open");
}

int
ext2_read (const char *path, char *buf, size_t size, off_t offset,
           struct fuse_file_info *fi)
{
  (void) path;
  (void) buf;
  (void) size;
  (void) offset;
  (void) fi;
  UNIMPL ("read");
}

int
ext2_write (const char *path, const char *buf, size_t size, off_t offset,
            struct fuse_file_info *fi)
{
  (void) path;
  (void) buf;
  (void) size;
  (void) offset;
  (void) fi;
  UNIMPL ("write");
}

int
ext2_statfs (const char *path, struct statvfs *stbuf)
{
  (void) path;
  (void) stbuf;
  UNIMPL ("statfs");
}

int
ext2_release (const char *path, struct fuse_file_info *fi)
{
  (void) path;
  (void) fi;
  UNIMPL ("release");
}

int
ext2_releasedir (const char *path, struct fuse_file_info *fi)
{
  (void) path;
  (void) fi;
  UNIMPL ("releasedir");
}

int
ext2_fsync (const char *path, int isdatasync, struct fuse_file_info *fi)
{
  (void) path;
  (void) isdatasync;
  (void) fi;
  UNIMPL ("fsync");
}

int
ext2_fsyncdir (const char *path, int isdatasync, struct fuse_file_info *fi)
{
  (void) path;
  (void) isdatasync;
  (void) fi;
  UNIMPL ("fsyncdir");
}

int
ext2_flush (const char *path, struct fuse_file_info *fi)
{
  (void) path;
  (void) fi;
  UNIMPL ("flush");
}

int
ext2_lock (const char *path, struct fuse_file_info *fi, int cmd,
           struct flock *locks)
{
  (void) path;
  (void) fi;
  (void) cmd;
  (void) locks;
  UNIMPL ("lock");
}

int
ext2_bmap (const char *path, size_t blocksize, uint64_t *blockno)
{
  (void) path;
  (void) blocksize;
  (void) blockno;
  UNIMPL ("bmap");
}

int
ext2_setxattr (const char *path, const char *name, const char *value,
               size_t size, int flags)
{
  (void) path;
  (void) name;
  (void) value;
  (void) size;
  (void) flags;
  UNIMPL ("setxattr");
}

int
ext2_getxattr (const char *path, const char *name, char *value, size_t size)
{
  (void) path;
  (void) name;
  (void) value;
  (void) size;
  UNIMPL ("getxattr");
}

int
ext2_listxattr (const char *path, char *list, size_t size)
{
  (void) path;
  (void) list;
  (void) size;
  UNIMPL ("listxattr");
}

int
ext2_ioctl (const char *path, int cmd, void *arg, struct fuse_file_info *fi,
            unsigned int flags, void *data)
{
  (void) path;
  (void) cmd;
  (void) arg;
  (void) fi;
  (void) flags;
  (void) data;
  UNIMPL ("ioctl");
}

int
ext2_poll (const char *path, struct fuse_file_info *fi,
           struct fuse_pollhandle *ph, unsigned *reventsp)
{
  (void) path;
  (void) fi;
  (void) ph;
  (void) reventsp;
  UNIMPL ("poll");
}