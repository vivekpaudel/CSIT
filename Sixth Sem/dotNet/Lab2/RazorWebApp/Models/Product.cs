using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace NorthwindDB.Models
{
    [Table("Products")]
    public class Product
    {
        [Key]
        public int ProductID { get; set; }

        public string ProductName { get; set; } = string.Empty;

        public decimal? UnitPrice { get; set; }
    }
}
