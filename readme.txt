Git is a version control system.
Git is free software.
（1）程序名称
WordCount
（2）功能说明
	程序统计文本文件（纯英文）的字符数或者单词数。空格，水平制表符，换行符均算字符。由空格或逗号分割开的都视为单词，且不做单词的有效性校验，例如：thi#,that视为用逗号隔开的2个单词。
（3）输入输出说明
	输入： [parameter] [input_file_name]
	注： [parameter]为控制参数，取”-c”和”-w”之一；[input_file_name]为要被处理的文本文件名，默认存放在执行文件目录下。
	输出：根据[parameter]为以下形式之一
		字符数：n
		单词数：n
		其中n为统计的字符数或单词数
