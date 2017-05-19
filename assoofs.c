static const struct super_operations assoofs_sops = {
.drop_inode     = generic_delete_inode ,
};


static struct dentry assoofs_mount(struct file_system_type *fs_type, int flags, const char *dev_name, void *data) {
   
           mount_bdev(fs_type, flags, dev_name, assoofs_fill_super);
}

//Operaciones
static struct inode_operations assoofs_inode_ops = {
	.create = assoofs_create,
	.lookup = assoofs_lookup,
	.mkdir = assoofs_mkdir,
};

struct dentry *assoofs_lookup(struct inode *parent_inode, struct *child_dentry, unsigned int flags) {
	printk("Lookup");
}

static int assoofs_create(struc inode *dir, struct dentry *dentry, umode_t mode, bool excl) {
	printk("Creando directorio");
}

static int assoofs_mkdir(struc inode *dir, struct dentry *dentry, umode_t mode) {
	printk("Creando directorio");
}


const struct file_operations assoofs_file_operations = {
	.read = assoofs_read,
	.write = assoofs_write,
};

const struct file_operations assoofs_dir_operations = {
	.owner = THIS_MODULE,
	.iterate = assoofs_iterate,
};

ssize_t assoofs_read(struct file *filp, char __user *buf, size_t len , loff_t *ppos) {
	printk("Leyendo";
}

ssize_t assoofs_write(struct file *filp, const char __user *buf, size_t len, loff_t *ppos) {
	printk("Escribiendo");
}

static int assoofs_iterate(struct file *filp, struct dir_context *ctx) {
	printk("Iterando");
}


int assoofs_fill_super(struct super_block *sb) {
	struct buffer_head buff;
	buff = sb_read(sb, 0);
	struct assoofs_superblock_info asb;
	asb = (struct assoofs_superblock_info *)buff->bdata;

	if(asb->magic != MAGIC) {
		printk("El numero magico no coincide");
		return -1;
	}
	if(asb->block_size != 4096) {
		printk("Tamaño de bloque incorrecto");
		return -1;
	}

	sb->s_magic = MAGIC;
	sb->s_maxbytes= asb->block_size;
	sb->s_fs_info = asb;
	sb->s_op = &assoofs_sops;

	struct *inode root_inode;
	root_inode = new_inode(sb);
	inode_init_owner(root_inode,NULL,S_IFDIR);

	root_inode->i_ino=1;
	root_inode->i_sb = sb;
	root_inode->i_atime = CURRENT_TIME;
	root_inode->i_mtime = CURRENT_TIME;
	root_inode->i_ctime = CURRENT_TIME;
	root_inode->i_op = ?;
	root_inode->i_fop = ?;

	d_make_root(root_inode);
}


static struct file_system_type assoofs_type = {
.owner = THIS_MODULE,
.name = "assoofs",
.mount = assoofs_mount,
.kill_sb = kill_litter_super,
};


void assoofs_init(assoofs_type) {

          register_filesystem(&assoofs_type)
}

void assoofs_exit(assoofs_type) {
 
           unregister_filesystem(&assoofs_type)
}


module_init(assoofs_init);
module_exit(assoofs_exit);
