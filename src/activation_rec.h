class activation_record
{
    // please let the private only
    // TODO: space for actual params
    uint64_t return_val; // return value
    uint64_t sp;         // stack pointer
    uint64_t saved_regs; // not sure how many regs
    uint64_t locals;     // may be more are needed
public:
    // some helper functions
    uint64_t get_return_val();
    uint64_t get_sp();
    uint64_t get_saved_regs();
    uint64_t get_locals();
    void set_return_val(uint64_t rv);
    void set_sp(uint64_t sp);
    void set_saved_regs(uint64_t sr);
    void set_locals(uint64_t l);
}