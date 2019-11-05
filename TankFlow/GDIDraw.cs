﻿using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TankFlow
{
    class GDIDraw
    {
        public static void Paint_Text(string str, Rectangle rect, Color font_color, Color border_color, Graphics g, float font_size)
        {
            FontFamily fontFamily = new FontFamily("微软雅黑");
            Font font = new Font(fontFamily, font_size, FontStyle.Bold, GraphicsUnit.Pixel);
            StringFormat format = StringFormat.GenericTypographic;
            float dpi = g.DpiY;
            using (GraphicsPath path = GetStringPath(str, dpi, rect, font, format))
            {
                Pen border_pen = new Pen(border_color, 0.6f);
                Brush font_brush = new SolidBrush(font_color);

                g.SmoothingMode = SmoothingMode.HighQuality;//设置字体质量
                g.DrawPath(border_pen, path);//绘制轮廓（描边）
                g.FillPath(font_brush, path);//填充轮廓（填充）
                rect.Offset(2, 2);
                GraphicsPath path1 = GetStringPath(str, dpi, rect, font, format);
            }

        }

 

        private static GraphicsPath GetStringPath(string s, float dpi, RectangleF rect, Font font, StringFormat format)
        {
            GraphicsPath path = new GraphicsPath();
            float emSize = dpi * font.SizeInPoints / 72;
            path.AddString(s, font.FontFamily, (int)font.Style, emSize, rect, format);
            return path;
        }

    }
}
