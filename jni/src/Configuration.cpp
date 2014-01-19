#include "Configuration.h"

void Configuration::Clear()
{
    data.clear();
}

bool Configuration::Load(const string& file)
{
	static Configuration _sConfigiration;

	AAsset *shaderAsset= AAssetManager_open(mAndroidContext->activity->assetManager, file.c_str(), AASSET_MODE_BUFFER);
	size_t length = AAsset_getLength(shaderAsset);

	LOGI("Config file size: %d\n", length);

	char* buffer = (char*) malloc(length);

	AAsset_read(shaderAsset, buffer, length);

	buffer[length - 1] = '\0';

	LOGI("Config file: %s\n", buffer);

	AAsset_close(shaderAsset);


	char * line = strtok(strdup(buffer), "\n");

	while(line) {
		std::string sline (line);

		// filter out comments
		if (!sline.empty())
		{
			int pos = sline.find('#');

			if (pos != (int)string::npos)
			{
				sline = sline.substr(0, pos);
			}
		}

		// split line into key and value
		if (!sline.empty())
		{

			int pos = sline.find('=');

			if (pos != (int)string::npos)
			{
				string key     = Trim(sline.substr(0, pos));
				string value   = Trim(sline.substr(pos + 1));

				if (!key.empty() && !value.empty())
				{
					data[key] = value;
				}
			}
		}
	   line  = strtok(NULL, "\n");
	}

    return true;
}

bool Configuration::Contains(const string& key) const
{
    return data.find(key) != data.end();
}

bool Configuration::Get(const string& key, string& value) const
{
    map<string,string>::const_iterator iter = data.find(key);

    if (iter != data.end())
    {
        value = iter->second;
        return true;
    }
    else
    {
        return false;
    }
}

bool Configuration::Get(const string& key, int& value) const
{
    string str;

    if (Get(key, str))
    {
        value = atoi(str.c_str());
        return true;
    }
    else
    {
        return false;
    }
}

bool Configuration::Get(const string& key, long& value) const
{
    string str;

    if (Get(key, str))
    {
        value = atol(str.c_str());
        return true;
    }
    else
    {
        return false;
    }
}

bool Configuration::Get(const string& key, double& value) const
{
    string str;

    if (Get(key, str))
    {
        value = atof(str.c_str());
        return true;
    }
    else
    {
        return false;
    }
}

bool Configuration::Get(const string& key, bool& value) const
{
    string str;

    if (Get(key, str))
    {
        value = (str == "true");
        return true;
    }
    else
    {
        return false;
    }
}

string Configuration::Trim(const string& str)
{
    int first = str.find_first_not_of(" \t");

    if (first != (int)string::npos)
    {
        int last = str.find_last_not_of(" \t");

        return str.substr(first, last - first + 1);
    }
    else
    {
        return "";
    }
}
