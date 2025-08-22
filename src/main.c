#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "ext2.h"

#define SUCCESS 0
#define ERROR   1

#define LINE(fmt, ...) printf (fmt "\n", ##__VA_ARGS__)
#define NAME(argv)     (argv)[0] ? (argv)[0] : ""
#define OPTION(t, p)   { t, offsetof (struct options, p), 1 }

int _dev;

static struct options
{
  int usage;
} options;

static const struct fuse_opt option_spec[]
    = { OPTION ("-h", usage), OPTION ("--help", usage), FUSE_OPT_END };

static struct fuse_operations ext2_ops = { .init = ext2_init,
                                           .destroy = ext2_destroy,
                                           .getattr = ext2_getattr,
                                           .fgetattr = ext2_fgetattr,
                                           .access = ext2_access,
                                           .readlink = ext2_readlink,
                                           .readdir = ext2_readdir,
                                           .mknod = ext2_mknod,
                                           .mkdir = ext2_mkdir,
                                           .symlink = ext2_symlink,
                                           .unlink = ext2_unlink,
                                           .rmdir = ext2_rmdir,
                                           .rename = ext2_rename,
                                           .link = ext2_link,
                                           .chmod = ext2_chmod,
                                           .chown = ext2_chown,
                                           .truncate = ext2_truncate,
                                           .ftruncate = ext2_ftruncate,
                                           .utimens = ext2_utimens,
                                           .create = ext2_create,
                                           .open = ext2_open,
                                           .read = ext2_read,
                                           .write = ext2_write,
                                           .statfs = ext2_statfs,
                                           .release = ext2_release,
                                           .opendir = ext2_opendir,
                                           .releasedir = ext2_releasedir,
                                           .fsync = ext2_fsync,
                                           .flush = ext2_flush,
                                           .fsyncdir = ext2_fsyncdir,
                                           .lock = ext2_lock,
                                           .bmap = ext2_bmap,
                                           .ioctl = ext2_ioctl,
                                           .poll = ext2_poll,
                                           .setxattr = ext2_setxattr,
                                           .getxattr = ext2_getxattr,
                                           .listxattr = ext2_listxattr,
                                           .flag_nullpath_ok = 0 };

static void
usage (const char *name)
{
  LINE ("usage: %s [OPTION]... dev mountpoint", name);
  LINE ("  dev: device or regular file that contains filesystem");
  LINE ("");
}

int
main (int argc, char *argv[])
{
  int ret;
  struct fuse_args args;
  const char *dev_path;

  if (argc < 3 || argv[argc - 2][0] == '-' || argv[argc - 1][0] == '-')
    {
      usage (NAME (argv));

      args = (struct fuse_args) FUSE_ARGS_INIT (argc, argv);
      if (fuse_opt_parse (&args, &options, option_spec, NULL) == -1)
        return ERROR;

      fuse_opt_add_arg (&args, "--help");
      fuse_main (args.argc, args.argv, &ext2_ops, NULL);
      fuse_opt_free_args (&args);

      return ERROR;
    }

  dev_path = realpath (argv[argc - 2], NULL);
  argv[argc - 2] = argv[argc - 1];
  --argc;

  args = (struct fuse_args) FUSE_ARGS_INIT (argc, argv);

  if (fuse_opt_parse (&args, &options, option_spec, NULL) == -1)
    return ERROR;

  if (options.usage)
    {
      usage (NAME (argv));
      fuse_opt_add_arg (&args, "--help");

      ret = fuse_main (args.argc, args.argv, &ext2_ops, NULL);
      fuse_opt_free_args (&args);

      return ret;
    }

  _dev = open (dev_path, O_RDONLY);
  if (_dev == -1)
    {
      fprintf (stderr, "failed to open dev: '%s'\n", dev_path);
      return ERROR;
    }

  ret = fuse_main (args.argc, args.argv, &ext2_ops, NULL);
  fuse_opt_free_args (&args);

  return ret;
}