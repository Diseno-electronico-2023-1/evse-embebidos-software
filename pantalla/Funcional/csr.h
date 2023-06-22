//--------------------------------------------------------------------------------
// Auto-generated by LiteX (782f045b) on 2023-06-15 08:04:55
//--------------------------------------------------------------------------------

#define CSR_BASE 0xf0000000L

#define MMPTR(a) (*((volatile uint32_t *)(a)))

static inline void csr_write_simple(unsigned long v, unsigned long a)
{
	MMPTR(a) = v;
}

static inline unsigned long csr_read_simple(unsigned long a)
{
	return MMPTR(a);
}

/* user_gpio */
#define CSR_USER_GPIO_BASE (CSR_BASE + 0x5800L)
#define CSR_USER_GPIO_OE_ADDR (CSR_BASE + 0x5800L)
#define CSR_USER_GPIO_OE_SIZE 1
static inline uint32_t user_gpio_oe_read(void) {
	return csr_read_simple((CSR_BASE + 0x5800L));
}
static inline void user_gpio_oe_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x5800L));
}
#define CSR_USER_GPIO_IN_ADDR (CSR_BASE + 0x5804L)
#define CSR_USER_GPIO_IN_SIZE 1
static inline uint32_t user_gpio_in_read(void) {
	return csr_read_simple((CSR_BASE + 0x5804L));
}
#define CSR_USER_GPIO_OUT_ADDR (CSR_BASE + 0x5808L)
#define CSR_USER_GPIO_OUT_SIZE 1
static inline uint32_t user_gpio_out_read(void) {
	return csr_read_simple((CSR_BASE + 0x5808L));
}
static inline void user_gpio_out_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x5808L));
}
#define CSR_USER_GPIO_MODE_ADDR (CSR_BASE + 0x580cL)
#define CSR_USER_GPIO_MODE_SIZE 1
static inline uint32_t user_gpio_mode_read(void) {
	return csr_read_simple((CSR_BASE + 0x580cL));
}
static inline void user_gpio_mode_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x580cL));
}
#define CSR_USER_GPIO_EDGE_ADDR (CSR_BASE + 0x5810L)
#define CSR_USER_GPIO_EDGE_SIZE 1
static inline uint32_t user_gpio_edge_read(void) {
	return csr_read_simple((CSR_BASE + 0x5810L));
}
static inline void user_gpio_edge_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x5810L));
}
#define CSR_USER_GPIO_EV_STATUS_ADDR (CSR_BASE + 0x5814L)
#define CSR_USER_GPIO_EV_STATUS_SIZE 1
static inline uint32_t user_gpio_ev_status_read(void) {
	return csr_read_simple((CSR_BASE + 0x5814L));
}
#define CSR_USER_GPIO_EV_STATUS_I0_OFFSET 0
#define CSR_USER_GPIO_EV_STATUS_I0_SIZE 1
static inline uint32_t user_gpio_ev_status_i0_extract(uint32_t oldword) {
	uint32_t mask = 0x1;
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_gpio_ev_status_i0_read(void) {
	uint32_t word = user_gpio_ev_status_read();
	return user_gpio_ev_status_i0_extract(word);
}
#define CSR_USER_GPIO_EV_STATUS_I1_OFFSET 1
#define CSR_USER_GPIO_EV_STATUS_I1_SIZE 1
static inline uint32_t user_gpio_ev_status_i1_extract(uint32_t oldword) {
	uint32_t mask = 0x1;
	return ( (oldword >> 1) & mask );
}
static inline uint32_t user_gpio_ev_status_i1_read(void) {
	uint32_t word = user_gpio_ev_status_read();
	return user_gpio_ev_status_i1_extract(word);
}
#define CSR_USER_GPIO_EV_STATUS_I2_OFFSET 2
#define CSR_USER_GPIO_EV_STATUS_I2_SIZE 1
static inline uint32_t user_gpio_ev_status_i2_extract(uint32_t oldword) {
	uint32_t mask = 0x1;
	return ( (oldword >> 2) & mask );
}
static inline uint32_t user_gpio_ev_status_i2_read(void) {
	uint32_t word = user_gpio_ev_status_read();
	return user_gpio_ev_status_i2_extract(word);
}
#define CSR_USER_GPIO_EV_STATUS_I3_OFFSET 3
#define CSR_USER_GPIO_EV_STATUS_I3_SIZE 1
static inline uint32_t user_gpio_ev_status_i3_extract(uint32_t oldword) {
	uint32_t mask = 0x1;
	return ( (oldword >> 3) & mask );
}
static inline uint32_t user_gpio_ev_status_i3_read(void) {
	uint32_t word = user_gpio_ev_status_read();
	return user_gpio_ev_status_i3_extract(word);
}
#define CSR_USER_GPIO_EV_PENDING_ADDR (CSR_BASE + 0x5818L)
#define CSR_USER_GPIO_EV_PENDING_SIZE 1
static inline uint32_t user_gpio_ev_pending_read(void) {
	return csr_read_simple((CSR_BASE + 0x5818L));
}
static inline void user_gpio_ev_pending_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x5818L));
}
#define CSR_USER_GPIO_EV_PENDING_I0_OFFSET 0
#define CSR_USER_GPIO_EV_PENDING_I0_SIZE 1
static inline uint32_t user_gpio_ev_pending_i0_extract(uint32_t oldword) {
	uint32_t mask = 0x1;
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_gpio_ev_pending_i0_read(void) {
	uint32_t word = user_gpio_ev_pending_read();
	return user_gpio_ev_pending_i0_extract(word);
}
static inline uint32_t user_gpio_ev_pending_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = 0x1;
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_gpio_ev_pending_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_gpio_ev_pending_read();
	uint32_t newword = user_gpio_ev_pending_i0_replace(oldword, plain_value);
	user_gpio_ev_pending_write(newword);
}
#define CSR_USER_GPIO_EV_PENDING_I1_OFFSET 1
#define CSR_USER_GPIO_EV_PENDING_I1_SIZE 1
static inline uint32_t user_gpio_ev_pending_i1_extract(uint32_t oldword) {
	uint32_t mask = 0x1;
	return ( (oldword >> 1) & mask );
}
static inline uint32_t user_gpio_ev_pending_i1_read(void) {
	uint32_t word = user_gpio_ev_pending_read();
	return user_gpio_ev_pending_i1_extract(word);
}
static inline uint32_t user_gpio_ev_pending_i1_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = 0x1;
	return (oldword & (~(mask << 1))) | (mask & plain_value)<< 1 ;
}
static inline void user_gpio_ev_pending_i1_write(uint32_t plain_value) {
	uint32_t oldword = user_gpio_ev_pending_read();
	uint32_t newword = user_gpio_ev_pending_i1_replace(oldword, plain_value);
	user_gpio_ev_pending_write(newword);
}
#define CSR_USER_GPIO_EV_PENDING_I2_OFFSET 2
#define CSR_USER_GPIO_EV_PENDING_I2_SIZE 1
static inline uint32_t user_gpio_ev_pending_i2_extract(uint32_t oldword) {
	uint32_t mask = 0x1;
	return ( (oldword >> 2) & mask );
}
static inline uint32_t user_gpio_ev_pending_i2_read(void) {
	uint32_t word = user_gpio_ev_pending_read();
	return user_gpio_ev_pending_i2_extract(word);
}
static inline uint32_t user_gpio_ev_pending_i2_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = 0x1;
	return (oldword & (~(mask << 2))) | (mask & plain_value)<< 2 ;
}
static inline void user_gpio_ev_pending_i2_write(uint32_t plain_value) {
	uint32_t oldword = user_gpio_ev_pending_read();
	uint32_t newword = user_gpio_ev_pending_i2_replace(oldword, plain_value);
	user_gpio_ev_pending_write(newword);
}
#define CSR_USER_GPIO_EV_PENDING_I3_OFFSET 3
#define CSR_USER_GPIO_EV_PENDING_I3_SIZE 1
static inline uint32_t user_gpio_ev_pending_i3_extract(uint32_t oldword) {
	uint32_t mask = 0x1;
	return ( (oldword >> 3) & mask );
}
static inline uint32_t user_gpio_ev_pending_i3_read(void) {
	uint32_t word = user_gpio_ev_pending_read();
	return user_gpio_ev_pending_i3_extract(word);
}
static inline uint32_t user_gpio_ev_pending_i3_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = 0x1;
	return (oldword & (~(mask << 3))) | (mask & plain_value)<< 3 ;
}
static inline void user_gpio_ev_pending_i3_write(uint32_t plain_value) {
	uint32_t oldword = user_gpio_ev_pending_read();
	uint32_t newword = user_gpio_ev_pending_i3_replace(oldword, plain_value);
	user_gpio_ev_pending_write(newword);
}
#define CSR_USER_GPIO_EV_ENABLE_ADDR (CSR_BASE + 0x581cL)
#define CSR_USER_GPIO_EV_ENABLE_SIZE 1
static inline uint32_t user_gpio_ev_enable_read(void) {
	return csr_read_simple((CSR_BASE + 0x581cL));
}
static inline void user_gpio_ev_enable_write(uint32_t v) {
	csr_write_simple(v, (CSR_BASE + 0x581cL));
}
#define CSR_USER_GPIO_EV_ENABLE_I0_OFFSET 0
#define CSR_USER_GPIO_EV_ENABLE_I0_SIZE 1
static inline uint32_t user_gpio_ev_enable_i0_extract(uint32_t oldword) {
	uint32_t mask = 0x1;
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_gpio_ev_enable_i0_read(void) {
	uint32_t word = user_gpio_ev_enable_read();
	return user_gpio_ev_enable_i0_extract(word);
}
static inline uint32_t user_gpio_ev_enable_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = 0x1;
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_gpio_ev_enable_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_gpio_ev_enable_read();
	uint32_t newword = user_gpio_ev_enable_i0_replace(oldword, plain_value);
	user_gpio_ev_enable_write(newword);
}
#define CSR_USER_GPIO_EV_ENABLE_I1_OFFSET 1
#define CSR_USER_GPIO_EV_ENABLE_I1_SIZE 1
static inline uint32_t user_gpio_ev_enable_i1_extract(uint32_t oldword) {
	uint32_t mask = 0x1;
	return ( (oldword >> 1) & mask );
}
static inline uint32_t user_gpio_ev_enable_i1_read(void) {
	uint32_t word = user_gpio_ev_enable_read();
	return user_gpio_ev_enable_i1_extract(word);
}
static inline uint32_t user_gpio_ev_enable_i1_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = 0x1;
	return (oldword & (~(mask << 1))) | (mask & plain_value)<< 1 ;
}
static inline void user_gpio_ev_enable_i1_write(uint32_t plain_value) {
	uint32_t oldword = user_gpio_ev_enable_read();
	uint32_t newword = user_gpio_ev_enable_i1_replace(oldword, plain_value);
	user_gpio_ev_enable_write(newword);
}
#define CSR_USER_GPIO_EV_ENABLE_I2_OFFSET 2
#define CSR_USER_GPIO_EV_ENABLE_I2_SIZE 1
static inline uint32_t user_gpio_ev_enable_i2_extract(uint32_t oldword) {
	uint32_t mask = 0x1;
	return ( (oldword >> 2) & mask );
}
static inline uint32_t user_gpio_ev_enable_i2_read(void) {
	uint32_t word = user_gpio_ev_enable_read();
	return user_gpio_ev_enable_i2_extract(word);
}
static inline uint32_t user_gpio_ev_enable_i2_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = 0x1;
	return (oldword & (~(mask << 2))) | (mask & plain_value)<< 2 ;
}
static inline void user_gpio_ev_enable_i2_write(uint32_t plain_value) {
	uint32_t oldword = user_gpio_ev_enable_read();
	uint32_t newword = user_gpio_ev_enable_i2_replace(oldword, plain_value);
	user_gpio_ev_enable_write(newword);
}
#define CSR_USER_GPIO_EV_ENABLE_I3_OFFSET 3
#define CSR_USER_GPIO_EV_ENABLE_I3_SIZE 1
static inline uint32_t user_gpio_ev_enable_i3_extract(uint32_t oldword) {
	uint32_t mask = 0x1;
	return ( (oldword >> 3) & mask );
}
static inline uint32_t user_gpio_ev_enable_i3_read(void) {
	uint32_t word = user_gpio_ev_enable_read();
	return user_gpio_ev_enable_i3_extract(word);
}
static inline uint32_t user_gpio_ev_enable_i3_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = 0x1;
	return (oldword & (~(mask << 3))) | (mask & plain_value)<< 3 ;
}
static inline void user_gpio_ev_enable_i3_write(uint32_t plain_value) {
	uint32_t oldword = user_gpio_ev_enable_read();
	uint32_t newword = user_gpio_ev_enable_i3_replace(oldword, plain_value);
	user_gpio_ev_enable_write(newword);
}