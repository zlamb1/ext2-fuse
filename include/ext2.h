#ifndef EXT2_H
#define EXT2_H 1

#include "_fuse.h"

typedef struct
{
  int dev;
} ext2fs_data_t;

void *ext2_init (struct fuse_conn_info *conn);
void ext2_destroy (void *private_data);
int ext2_getattr (const char *path, struct stat *stbuf);
int ext2_fgetattr (const char *path, struct stat *stbuf,
                   struct fuse_file_info *fi);
int ext2_access (const char *path, int mask);
int ext2_readlink (const char *path, char *buf, size_t size);
int ext2_opendir (const char *path, struct fuse_file_info *fi);
int ext2_readdir (const char *path, void *buf, fuse_fill_dir_t filler,
                  off_t offset, struct fuse_file_info *fi);
int ext2_mknod (const char *path, mode_t mode, dev_t rdev);
int ext2_mkdir (const char *path, mode_t mode);
int ext2_unlink (const char *path);
int ext2_rmdir (const char *path);
int ext2_symlink (const char *to, const char *from);
int ext2_rename (const char *from, const char *to);
int ext2_link (const char *from, const char *to);
int ext2_chmod (const char *path, mode_t mode);
int ext2_chown (const char *path, uid_t uid, gid_t gid);
int ext2_truncate (const char *path, off_t size);
int ext2_ftruncate (const char *path, off_t size, struct fuse_file_info *fi);
int ext2_utimens (const char *path, const struct timespec ts[2]);
int ext2_create (const char *path, mode_t mode, struct fuse_file_info *fi);
int ext2_open (const char *path, struct fuse_file_info *fi);
int ext2_read (const char *path, char *buf, size_t size, off_t offset,
               struct fuse_file_info *fi);
int ext2_write (const char *path, const char *buf, size_t size, off_t offset,
                struct fuse_file_info *fi);
int ext2_statfs (const char *path, struct statvfs *stbuf);
int ext2_release (const char *path, struct fuse_file_info *fi);
int ext2_releasedir (const char *path, struct fuse_file_info *fi);
int ext2_fsync (const char *path, int isdatasync, struct fuse_file_info *fi);
int ext2_fsyncdir (const char *path, int isdatasync,
                   struct fuse_file_info *fi);
int ext2_flush (const char *path, struct fuse_file_info *fi);
int ext2_lock (const char *path, struct fuse_file_info *fi, int cmd,
               struct flock *locks);
int ext2_bmap (const char *path, size_t blocksize, uint64_t *blockno);
int ext2_setxattr (const char *path, const char *name, const char *value,
                   size_t size, int flags);
int ext2_getxattr (const char *path, const char *name, char *value,
                   size_t size);
int ext2_listxattr (const char *path, char *list, size_t size);
int ext2_ioctl (const char *path, int cmd, void *arg,
                struct fuse_file_info *fi, unsigned int flags, void *data);
int ext2_poll (const char *path, struct fuse_file_info *fi,
               struct fuse_pollhandle *ph, unsigned *reventsp);

#endif