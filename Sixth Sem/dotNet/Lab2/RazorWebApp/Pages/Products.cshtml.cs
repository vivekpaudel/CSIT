using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using NorthwindDB.Models;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace RazorWebApp.Pages
{
    public class ProductsModel : PageModel
    {
        private readonly NorthwindContext _context;

        public ProductsModel(NorthwindContext context)
        {
            _context = context;
        }

        public IList<Product> Products { get; set; } = new List<Product>();

        public async Task OnGetAsync()
        {
            // Asynchronously query database, sorting items by price ascending
            Products = await _context.Products
                .OrderBy(p => p.UnitPrice)
                .ToListAsync();
        }
    }
}
