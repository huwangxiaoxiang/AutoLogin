using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TankFlow
{
    static class MySqlAPI
    {
        static string IP="47.101.70.188";
        static int port = 3306;
        static string username = "xiaoxiang";
        static string password = "123456";
        static string database = "tank";
        private static MySqlConnection con = null;
  

        public static bool ConnectServer()
        {

            string connStr = "server=" + IP + ";port=" + port.ToString() + ";user=" + username + ";password=" + password + ";database=" + database+ ";Charset=utf8";
            try
            {
                if (con == null)
                {
                    con = new MySqlConnection(connStr);
                    con.Open();
                }
                else if (con.State == ConnectionState.Closed || con.State == ConnectionState.Broken)
                    con.Open();
                return true;
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
                return false;
            }
        }

        public static bool CloseServer()
        {
            try
            {
                if (con != null)
                    con.Close();
                con = null;
                return true;
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
                return false;
            }
        }

        public static int ExecuteProcedure(string pro_name, Param param)
        {
            int result = -1;
            if (!ConnectServer())
                return -1;
            List<MySqlParameter> parameters = param.getLists();
            MySqlCommand cmd = new MySqlCommand(pro_name, con);
            cmd.CommandType = CommandType.StoredProcedure;
            // MySqlParameter outr = new MySqlParameter("",MySqlDbType.VarChar,18);
            if (parameters == null) parameters = new List<MySqlParameter>();
            
            foreach (MySqlParameter para in parameters)
            {
                cmd.Parameters.Add(para);
            }
            try
            {
                MySqlDataReader reader = cmd.ExecuteReader(CommandBehavior.SingleRow);
                if (reader.HasRows)
                {
                    result = reader.GetInt16(0);
                }
                reader.Close();
            }catch(Exception e)
            {
                Log.AddLog(e.Message);
            }
            return result;
        }
    }
}
