#ifndef FILE_SPRITER_HPP_
#define FILE_SPRITER_HPP_

class FileSpritter {
  public:
    FileSpritter(const char *const data, int size);
    char *get_sprit_data(int rowCount) const;
    int get_row_count() const;

  private:
    int m_row_count;
    char *m_sprit_data[];
};

#endif
